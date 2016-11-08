#include "stdafx.h"
#include "libchapter3.h"
#include "IdentitySphere.h"
#include <algorithm>


namespace
{
const unsigned MIN_PRECISION = 4;

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

void CalculateTriangleStripIndicies(std::vector<uint32_t> &indicies, size_t size)
{
	indicies.clear();
	indicies.reserve(size);
	glEnableClientState(GL_PRIMITIVE_RESTART_NV);
	for (unsigned ci = 0; ci != size; ++ci)
	{
		indicies.push_back(ci);
	}
	glDisableClientState(GL_PRIMITIVE_RESTART_NV);
}


/// Привязывает вершины к состоянию OpenGL,
/// затем вызывает 'callback'.
template <class T>
void DoWithBindedArrays(const std::vector<SVertexP3NT2> &vertices, T && callback)
{
    glEnableClientState(GL_VERTEX_ARRAY);

    // Выполняем привязку vertex array и normal array
    const size_t stride = sizeof(SVertexP3NT2);
    glVertexPointer(3, GL_FLOAT, stride, glm::value_ptr(vertices[0].position));

    // Выполняем внешнюю функцию.
    callback();

    glDisableClientState(GL_VERTEX_ARRAY);
}

glm::vec3 GetPositionOnSphere(float u, float v)
{
    const float radius = 1.f;
    const float latitude = float(M_PI) * (1.f - v); // 𝝅∙(𝟎.𝟓-𝒗)
    const float longitude = float(2.0 * M_PI) * u; // 𝟐𝝅∙𝒖
    const float latitudeRadius = radius * sinf(latitude);

    return { cosf(longitude) * latitudeRadius,
             cosf(latitude) * radius,
             sinf(longitude) * latitudeRadius };
}

glm::vec3 GetPositionPoint(float x)
{
	auto GetRadius = [](float x)
	{
		return (1.f + sinf(x)) * (1.f + 0.9f * cosf(8.f * x)) * (1.f + 0.1f * cosf(24.f * x)) * (0.5f + 0.05f * cosf(140.f * x));
	};

	return{ GetRadius(x) * cosf(x), GetRadius(x) * sinf(x), 0.f };

}
}



CIdentitySphere::CIdentitySphere(unsigned slices, unsigned stacks)
{
    Tesselate(slices, stacks);
}

void CIdentitySphere::Draw() const
{
	auto drawModeForPolygon = !m_isChangePolygonDrawMode ? GL_FILL : GL_LINE;
	glPolygonMode(GL_FRONT_AND_BACK, drawModeForPolygon);

    DoWithBindedArrays(m_vertices, [this]() {
        glDrawElements(GL_LINE_STRIP, GLsizei(m_indicies.size()),
                       GL_UNSIGNED_INT, m_indicies.data());
    });
}

void CIdentitySphere::ChangePolygonDrawMode()
{
	m_isChangePolygonDrawMode = !m_isChangePolygonDrawMode;
}

void CIdentitySphere::ChangeCalculateMode()
{
	m_isChangeDrawMode = !m_isChangeDrawMode;
	if (m_isChangeDrawMode)
	{
		CalculateTriangleStripIndicies(m_indicies, m_vertices.size());
	}
	else
	{
		CalculateTriangleStripIndicies(m_indicies, 40, 50);
	}
}

void CIdentitySphere::Tesselate(unsigned slices, unsigned stacks)
{
	const float step = M_PI / 1000;
	for (float x = 0.f; x <= M_PI * 2; x += step)
	{
		SVertexP3NT2 vertex;
		vertex.position = GetPositionPoint(x);
		vertex.normal = vertex.position;
		m_vertices.push_back(vertex);
	}
	CalculateTriangleStripIndicies(m_indicies, 40, 50);
	
}
