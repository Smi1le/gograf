#include "stdafx.h"
#include "FunctionSurface.h"
#include <algorithm>

namespace
{
const float DOT_SIZE = 5.f;

glm::vec3 GetPosition(const Function2D &fn, float x, float z)
{
    const float y = fn(x, z);
    return {x, y, z};
}

// вычисляет нормали численным методом,
// с помощью векторного произведения.
void CalculateNormals(std::vector<SVertexP3N> &vertices, float step)
{
    for (SVertexP3N &v : vertices)
    {
        const glm::vec3 &position = v.position;
        glm::vec3 dir1 = glm::vec3(position.y, position.x, position.z + step) - position;
		glm::vec3 dir2 = glm::vec3(position.y, position.x + step, position.z) - position;
        v.normal = glm::normalize(glm::cross(dir1, dir2));
    }
}

/// Привязывает вершины к состоянию OpenGL,
/// затем вызывает 'callback'.
template <class T>
void DoWithBindedArrays(const std::vector<SVertexP3N> &vertices, T && callback)
{
    // Включаем режим vertex array и normal array.
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    // Выполняем привязку vertex array и normal array
	//glColor({1.0f, 0.f, 0.f, 1.f});

    const size_t stride = sizeof(SVertexP3N);
    glNormalPointer(GL_FLOAT, stride, glm::value_ptr(vertices[0].normal));
    glVertexPointer(3, GL_FLOAT, stride, glm::value_ptr(vertices[0].position));

    // Выполняем внешнюю функцию.
    callback();

    // Выключаем режим vertex array и normal array.
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

void CalculateTriangleStripIndicies(std::vector<uint32_t> &indicies,
                                    unsigned columnCount, unsigned rowCount)
{
    indicies.clear();
    indicies.reserve((columnCount - 1) * rowCount * 2);
    // вычисляем индексы вершин.
    for (unsigned ci = 0; ci < columnCount - 1; ++ci)
    {
        if (ci % 2 == 0)
        {
            for (unsigned ri = 0; ri < rowCount; ++ri)
            {
                unsigned index = ci * rowCount + ri;
                indicies.push_back(index + rowCount);
                indicies.push_back(index);
            }
        }
        else
        {
            for (unsigned ri = rowCount - 1; ri < rowCount; --ri)
            {
                unsigned index = ci * rowCount + ri;
                indicies.push_back(index);
                indicies.push_back(index + rowCount);
            }
        }
    }
}
}

CSolidFunctionSurface::CSolidFunctionSurface(const Function2D &fnForX, const Function2D &fnForY, const Function2D &fnForZ)
    : m_functionForX(fnForX)
	, m_functionForY(fnForY)
	, m_functionForZ(fnForZ)
{}

void CSolidFunctionSurface::ChangeMode()
{
	m_isFrame = !m_isFrame;
}

void CSolidFunctionSurface::Tesselate(const glm::vec2 &rangeX, const glm::vec2 &rangeZ, float step)
{
    const unsigned columnCount = unsigned((rangeX.y - rangeX.x) / step);
    const unsigned rowCount = unsigned((rangeZ.y - rangeZ.x) / step);
    m_vertices.clear();
    m_vertices.reserve(columnCount * rowCount);

    // вычисляем позиции вершин.
    for (unsigned ci = 0; ci < columnCount; ++ci)
    {
        const float x = rangeX.x + step * float(ci);
        for (unsigned ri = 0; ri < rowCount; ++ri)
        {
            const float z = rangeZ.x + step * float(ri);
            m_vertices.push_back(SVertexP3N(glm::vec3(m_functionForX(x, z), m_functionForY(x, z), m_functionForZ(x, z))));
        }
    }
    CalculateNormals(m_vertices, step);
    CalculateTriangleStripIndicies(m_indicies, columnCount, rowCount);
}

void CSolidFunctionSurface::Draw() const
{	
	auto mode = !m_isFrame ? GL_TRIANGLE_STRIP : GL_LINE_STRIP;

	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);

	DoWithBindedArrays(m_vertices, [&] {
		glDrawElements(mode, GLsizei(m_indicies.size()),
			GL_UNSIGNED_INT, m_indicies.data());
	});

	glCullFace(GL_FRONT);

	DoWithBindedArrays(m_vertices, [&] {
		glDrawElements(mode, GLsizei(m_indicies.size()),
			GL_UNSIGNED_INT, m_indicies.data());
	});
}
