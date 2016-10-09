#include "stdafx.h"
#include "Bodies.h"
#include <stdint.h>

namespace
{

typedef glm::vec3 Vertex;

const glm::vec4 DARK_BLUE = {0.05f, 0.1f, 0.5f, 0.5f};
const glm::vec4 LIGHT_RED = {0.8f, 0.1f, 0.15f, 0.5f};

// Вершины куба служат материалом для формирования треугольников,
// составляющих грани куба.
/*const Vertex CUBE_VERTICIES[] = {
    {-1, +1, -1},
    {+1, +1, -1},
    {+1, -1, -1},
    {-1, -1, -1},
    {-1, +1, +1},
    {+1, +1, +1},
    {+1, -1, +1},
    {-1, -1, +1},
};*/

struct STriangleFace
{
	uint16_t vertexIndex1;
	uint16_t vertexIndex2;
	uint16_t vertexIndex3;
	uint16_t colorIndex;
};

// Привыкаем использовать 16-битный unsigned short,
// чтобы экономить память на фигурах с тысячами вершин.
/*const STriangleFace CUBE_FACES[] = {
	{ 0, 1, 2, static_cast<uint16_t>(CubeFace::Back) },
	{ 0, 2, 3, static_cast<uint16_t>(CubeFace::Back) },
	{ 2, 1, 5, static_cast<uint16_t>(CubeFace::Right) },
	{ 2, 5, 6, static_cast<uint16_t>(CubeFace::Right) },
	{ 3, 2, 6, static_cast<uint16_t>(CubeFace::Bottom) },
	{ 3, 6, 7, static_cast<uint16_t>(CubeFace::Bottom) },
	{ 0, 3, 7, static_cast<uint16_t>(CubeFace::Left) },
	{ 0, 7, 4, static_cast<uint16_t>(CubeFace::Left) },
	{ 1, 0, 4, static_cast<uint16_t>(CubeFace::Top) },
	{ 1, 4, 5, static_cast<uint16_t>(CubeFace::Top) },
	{ 6, 5, 4, static_cast<uint16_t>(CubeFace::Front) },
	{ 6, 4, 7, static_cast<uint16_t>(CubeFace::Front) },
};
*/
const Vertex CUBE_VERTICIES[] = {
	{0.408f, -0.371f, 0.597f},
	{-0.146f, -0.733f, 0.321f},
	{-0.227f, -0.503f, 0.597f},
	{0.630f, -0.051f, 0.512f},
	{-0.652f, -0.45f, 0.183f},
	{-0.081f, -0.806f, -0.065f},
	{-0.313f, -0.678f, -0.321f},
	{0.652f, 0.365f, -0.321f},
	{0.227f, 0.759f, -0.183f},
	{0.243f, -0.583f, -0.512f},
	{-0.243f, 0.197f, 0.750f},
	{0.479f, 0.274f, 0.597f},
	{-0.54f, -0.329f, 0.512f},
	{0.313f, -0.016f, 0.750f},
	{0.146f, -0.615f, 0.512f},
	{0.081f, -0.302f, 0.750f},
	{-0.262f, -0.171f, 0.750f},
	{0.262f, -0.747f, -0.183f},
	{-0.408f, -0.7f, 0.065f},
	{-0.652f, 0.45f, -0.183f},
	{0.112f, -0.292f, -0.750f},
	{0.479f, -0.274f, -0.597f},
	{0.408f, 0.371f, -0.597f},
	{-0.227f, 0.503f, -0.597f},
	{0.630f, 0.051f, -0.512f},
	{0.146f, 0.615f, -0.512f},
	{0.081f, 0.302f, -0.750f},
	{-0.540f, 0.32f, -0.512f},
	{-0.112f, -0.54f, -0.597f},
	{0.313f, 0.016f, -0.750f},
	{-0.630f, -0.479f, -0.183f},
	{-0.742f, 0.088f, -0.321f},
	{-0.792f, 0.172f, 0.065f},
	{-0.408f, 0.7f, -0.065f},
	{-0.630f, 0.479f, 0.183f},
	{-0.112f, 0.540f, 0.597f},
	{0.112f, 0.292f, 0.75f},
	{-0.479f, 0.412f, 0.512f},
	{-0.549f, 0.060f, 0.597f},
	{0.549f, 0.507f, 0.321f},
	{-0.081f, 0.806f, 0.065f},
	{0.540f, 0.605f, -0.065f},
	{0.742f, -0.326f, -0.065f},
	{-0.742f, -0.088f, 0.321f},
	{-0.792f, -0.171f, -0.065f},
	{0.742f, 0.326f, 0.065f},
	{0.792f, -0.019f, 0.183f},
	{0.54f, -0.605f, 0.065f},
	{0.243f, 0.583f, 0.512f},
	{0.652f, -0.365f, 0.321f},
	{0.227f, -0.759f, 0.183f},
	{-0.313f, 0.678f, 0.321f},
	{-0.262f, 0.172f, -0.750f},
	{-0.243f, -0.197f, -0.750f},
	{-0.549f, -0.06f, -0.597f},
	{-0.479f, -0.412f, -0.512f},
	{-0.146f, 0.733f, -0.321f},
	{0.549f, -0.507f, -0.321f},
	{0.262f, 0.747f, 0.183f},
	{0.792f, 0.019f, -0.183f},
};

const STriangleFace CUBE_FACES[] = {
{ 16, 15, 13, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 16, 13, 36, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 16, 36, 10, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 18, 1, 2, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 18, 2, 12, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 18, 12, 4, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 51, 35, 48, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 51, 48, 58, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 51, 58, 40, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 39, 11, 3, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 39, 3, 46, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 39, 46, 45, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 47, 49, 0, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 47, 0, 14, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 47, 14, 50, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 43, 38, 37, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 43, 37, 34, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 43, 34, 32, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 26, 29, 20, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 26, 20, 53, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 26, 53, 52, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 33, 56, 23, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 33, 23, 27, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 33, 27, 19, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 9, 17, 5, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 9, 5, 6, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 9, 6, 28, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 59, 42, 57, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 59, 57, 21, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 59, 21, 24, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 22, 25, 8, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 22, 8, 41, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 22, 41, 7, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 31, 54, 55, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 31, 55, 30, static_cast<uint16_t>(ShapeFace::pentagon) },
{ 31, 30, 44, static_cast<uint16_t>(ShapeFace::pentagon) },

{ 10, 35, 37, static_cast<uint16_t>(ShapeFace::triangle) },
{ 36, 11, 48, static_cast<uint16_t>(ShapeFace::triangle) },
{ 13, 0, 3, static_cast<uint16_t>(ShapeFace::triangle) },
{ 15, 2, 14, static_cast<uint16_t>(ShapeFace::triangle) },
{ 16, 38, 12, static_cast<uint16_t>(ShapeFace::triangle) },
{ 51, 33, 34, static_cast<uint16_t>(ShapeFace::triangle) },
{ 39, 41, 58, static_cast<uint16_t>(ShapeFace::triangle) },
{ 49, 42, 46, static_cast<uint16_t>(ShapeFace::triangle) },
{ 1, 5, 50, static_cast<uint16_t>(ShapeFace::triangle) },
{ 43, 44, 4, static_cast<uint16_t>(ShapeFace::triangle) },
{ 40, 8, 56, static_cast<uint16_t>(ShapeFace::triangle) },
{ 45, 59, 7, static_cast<uint16_t>(ShapeFace::triangle) },
{ 47, 17, 57, static_cast<uint16_t>(ShapeFace::triangle) },
{ 18, 30, 6, static_cast<uint16_t>(ShapeFace::triangle) },
{ 32, 19, 31, static_cast<uint16_t>(ShapeFace::triangle) },
{ 53, 28, 55, static_cast<uint16_t>(ShapeFace::triangle) },
{ 20, 21, 9, static_cast<uint16_t>(ShapeFace::triangle) },
{ 29, 22, 24, static_cast<uint16_t>(ShapeFace::triangle) },
{ 26, 23, 25, static_cast<uint16_t>(ShapeFace::triangle) },
{ 52, 54, 27, static_cast<uint16_t>(ShapeFace::triangle) },

{ 10, 36, 35, static_cast<uint16_t>(ShapeFace::triangle) },
{ 36, 13, 11, static_cast<uint16_t>(ShapeFace::triangle) },
{ 13, 15, 0, static_cast<uint16_t>(ShapeFace::triangle) },
{ 15, 16, 2, static_cast<uint16_t>(ShapeFace::triangle) },
{ 16, 10, 38, static_cast<uint16_t>(ShapeFace::triangle) },
{ 48, 35, 36, static_cast<uint16_t>(ShapeFace::triangle) },
{ 3, 11, 13, static_cast<uint16_t>(ShapeFace::triangle) },
{ 14, 0, 15, static_cast<uint16_t>(ShapeFace::triangle) },
{ 12, 2, 16, static_cast<uint16_t>(ShapeFace::triangle) },
{ 37, 38, 10, static_cast<uint16_t>(ShapeFace::triangle) },
{ 35, 51, 37, static_cast<uint16_t>(ShapeFace::triangle) },
{ 11, 39, 48, static_cast<uint16_t>(ShapeFace::triangle) },
{ 0, 49, 3, static_cast<uint16_t>(ShapeFace::triangle) },
{ 2, 1, 14, static_cast<uint16_t>(ShapeFace::triangle) },
{ 38, 43, 12, static_cast<uint16_t>(ShapeFace::triangle) },
{ 51, 40, 33, static_cast<uint16_t>(ShapeFace::triangle) },
{ 39, 45, 41, static_cast<uint16_t>(ShapeFace::triangle) },
{ 49, 47, 42, static_cast<uint16_t>(ShapeFace::triangle) },
{ 1, 18, 5, static_cast<uint16_t>(ShapeFace::triangle) },
{ 43, 32, 44, static_cast<uint16_t>(ShapeFace::triangle) },
{ 40, 58, 8, static_cast<uint16_t>(ShapeFace::triangle) },

{ 45, 46, 59, static_cast<uint16_t>(ShapeFace::triangle) },
{ 47, 50, 17, static_cast<uint16_t>(ShapeFace::triangle) },
{ 18, 4, 30, static_cast<uint16_t>(ShapeFace::triangle) },
{ 32, 34, 19, static_cast<uint16_t>(ShapeFace::triangle) },
{ 58, 48, 39, static_cast<uint16_t>(ShapeFace::triangle) },
{ 46, 3, 49, static_cast<uint16_t>(ShapeFace::triangle) },
{ 50, 14, 1, static_cast<uint16_t>(ShapeFace::triangle) },
{ 4, 12, 43, static_cast<uint16_t>(ShapeFace::triangle) },
{ 34, 37, 51, static_cast<uint16_t>(ShapeFace::triangle) },
{ 53, 20, 28, static_cast<uint16_t>(ShapeFace::triangle) },
{ 20, 29, 21, static_cast<uint16_t>(ShapeFace::triangle) },
{ 29, 26, 22, static_cast<uint16_t>(ShapeFace::triangle) },
{ 26, 52, 23, static_cast<uint16_t>(ShapeFace::triangle) },
{ 52, 53, 54, static_cast<uint16_t>(ShapeFace::triangle) },
{ 9, 28, 20, static_cast<uint16_t>(ShapeFace::triangle) },
{ 24, 21, 29, static_cast<uint16_t>(ShapeFace::triangle) },
{ 25, 22, 26, static_cast<uint16_t>(ShapeFace::triangle) },
{ 27, 23, 52, static_cast<uint16_t>(ShapeFace::triangle) },
{ 55, 54, 53, static_cast<uint16_t>(ShapeFace::triangle) },
{ 28, 6, 55, static_cast<uint16_t>(ShapeFace::triangle) },

{ 21, 57, 9, static_cast<uint16_t>(ShapeFace::triangle) },
{ 22, 7, 24, static_cast<uint16_t>(ShapeFace::triangle) },
{ 23, 56, 25, static_cast<uint16_t>(ShapeFace::triangle) },
{ 54, 31, 27, static_cast<uint16_t>(ShapeFace::triangle) },
{ 6, 5, 18, static_cast<uint16_t>(ShapeFace::triangle) },
{ 57, 42, 47, static_cast<uint16_t>(ShapeFace::triangle) },
{ 7, 41, 45, static_cast<uint16_t>(ShapeFace::triangle) },
{ 56, 33, 40, static_cast<uint16_t>(ShapeFace::triangle) },
{ 31, 44, 32, static_cast<uint16_t>(ShapeFace::triangle) },
{ 5, 17, 50, static_cast<uint16_t>(ShapeFace::triangle) },
{ 42, 59, 46, static_cast<uint16_t>(ShapeFace::triangle) },
{ 41, 8, 58, static_cast<uint16_t>(ShapeFace::triangle) },
{ 33, 19, 34, static_cast<uint16_t>(ShapeFace::triangle) },
{ 44, 30, 4, static_cast<uint16_t>(ShapeFace::triangle) },
{ 17, 9, 57, static_cast<uint16_t>(ShapeFace::triangle) },
{ 59, 24, 7, static_cast<uint16_t>(ShapeFace::triangle) },
{ 8, 25, 56, static_cast<uint16_t>(ShapeFace::triangle) },
{ 19, 27, 31, static_cast<uint16_t>(ShapeFace::triangle) },
{ 30, 55, 6, static_cast<uint16_t>(ShapeFace::triangle) }
};

/*const uint16_t EDGES_CUBE_FACES[] = {
	0, 1, 5, 4,
	0, 3, 2, 6,
	7, 3, 2, 1,
	5, 6, 7, 4,
};*/

/// @param phase - Фаза анимации на отрезке [0..1]
glm::mat4 GetRotateZTransfrom(float phase)
{
    // угол вращения вокруг оси Z лежит в отрезке [0...2*pi].
    const float angle = float(2 * M_PI) * phase;

    return glm::rotate(glm::mat4(), angle, {0, 0, 1});
}

/// @param phase - Фаза анимации на отрезке [0..1]
glm::mat4 GetScalingPulseTransform(float phase)
{
    // число пульсаций размера - произвольная константа.
    const int pulseCount = 4;
    float scale = fabsf(cosf(float(pulseCount * M_PI) * phase));

    return glm::scale(glm::mat4(), {scale, scale, scale});
}

/// @param phase - Фаза анимации на отрезке [0..1]
glm::mat4 GetBounceTransform(float phase)
{
    // начальная скорость и число отскоков - произвольные константы.
    const int bounceCount = 4;
    const float startSpeed = 15.f;
    // "время" пробегает bounceCount раз по отрезку [0...1/bounceCount].
    const float time = fmodf(phase, 1.f / float(bounceCount));
    // ускорение подбирается так, чтобы на 0.25с скорость стала
    // противоположна начальной.
    const float acceleration = - (startSpeed * 2.f * float(bounceCount));
    // расстояние - результат интегрирования функции скорости:
    //  speed = startSpeed + acceleration * time;
    float offset = time * (startSpeed + 0.5f * acceleration * time);

    // для отскоков с нечётным номером меняем знак.
    const int bounceNo = int(phase * bounceCount);
    if (bounceNo % 2)
    {
        offset = -offset;
    }

    return glm::translate(glm::mat4(), {offset, 0.f, 0.f});
}

}

CIdentityCube::CIdentityCube()
{
	// Используем белый цвет по умолчанию.
	for (glm::vec4 &color : m_colors)
	{
		color.x = 1;
		color.y = 1;
		color.z = 1;
		color.w = 1;
	}
}

void CIdentityCube::Update(float deltaTime)
{
    (void)deltaTime;
}

void CIdentityCube::Draw() const
{
	
	//glEnable(GL_DEPTH_TEST);
	/*glDepthMask(GL_TRUE);
	glLineWidth(2.f);
	glBegin(GL_LINE_LOOP);
	for (uint16_t i : EDGES_CUBE_FACES)
	{
		const Vertex &v = CUBE_VERTICIES[i];
		glColor4f(1.f, 1.f, 1.f, 1.f);
		glVertex3f(v.x, v.y, v.z);
	}
	glEnd();

	glDepthMask(GL_FALSE);*/
	//glDisable(GL_DEPTH_TEST);

    // менее оптимальный способ рисования: прямая отправка данных
    // могла бы работать быстрее, чем множество вызовов glColor/glVertex.
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_CULL_FACE);
	
	glCullFace(GL_FRONT);
	glBegin(GL_TRIANGLES);

	for (const STriangleFace &face : CUBE_FACES)
	{
		const Vertex &v1 = CUBE_VERTICIES[face.vertexIndex1];
		const Vertex &v2 = CUBE_VERTICIES[face.vertexIndex2];
		const Vertex &v3 = CUBE_VERTICIES[face.vertexIndex3];
		if (v1.x > 1 || v1.y > 1 || v1.z > 1 || v1.x < -1 || v1.y < -1 || v1.z < -1)
		{
			std::cout << "face.vertexIndex1 = " << face.vertexIndex1 << std::endl;
		}
		glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v1));

		glColor4fv(glm::value_ptr(m_colors[face.colorIndex]));
		glNormal3fv(glm::value_ptr(normal));
		glVertex3fv(glm::value_ptr(v1));
		glVertex3fv(glm::value_ptr(v2));
		glVertex3fv(glm::value_ptr(v3));
	}
	glEnd();
	
	glCullFace(GL_BACK);
	glBegin(GL_TRIANGLES);

	for (const STriangleFace &face : CUBE_FACES)
	{
		const Vertex &v1 = CUBE_VERTICIES[face.vertexIndex1];
		const Vertex &v2 = CUBE_VERTICIES[face.vertexIndex2];
		const Vertex &v3 = CUBE_VERTICIES[face.vertexIndex3];
		glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v1));

		glColor4fv(glm::value_ptr(m_colors[face.colorIndex]));
		glNormal3fv(glm::value_ptr(normal));
		glVertex3fv(glm::value_ptr(v1));
		glVertex3fv(glm::value_ptr(v2));
		glVertex3fv(glm::value_ptr(v3));
	}
	glEnd();
	glDisable(GL_BLEND);
}

void CIdentityCube::SetFaceColor(ShapeFace face, const glm::vec4 &color)
{
	const size_t index = static_cast<size_t>(face);
	assert(index < COLORS_COUNT);
	m_colors[index] = color;
}


const float CAnimatedCube::ANIMATION_STEP_SECONDS = 2.f;

void CAnimatedCube::Update(float deltaTime)
{
    // Вычисляем фазу анимации по времени на отрезке [0..1].
    m_animationPhase += (deltaTime / ANIMATION_STEP_SECONDS);
    if (m_animationPhase >= 1)
    {
        m_animationPhase = 0;
        switch (m_animation)
        {
        case Rotating:
            m_animation = Pulse;
            break;
        case Pulse:
            m_animation = Bounce;
            break;
        case Bounce:
            m_animation = Rotating;
            break;
        }
    }
}

void CAnimatedCube::Draw() const
{
    const glm::mat4 matrix = GetAnimationTransform();
    glPushMatrix();
    glMultMatrixf(glm::value_ptr(matrix));
    CIdentityCube::Draw();
    glPopMatrix();
}

// Документация по функциям для модификации матриц:
// http://glm.g-truc.net/0.9.2/api/a00245.html
glm::mat4 CAnimatedCube::GetAnimationTransform() const
{
    switch (m_animation)
    {
    case Rotating:
        return GetRotateZTransfrom(m_animationPhase);
    case Pulse:
        return GetScalingPulseTransform(m_animationPhase);
    case Bounce:
        return GetBounceTransform(m_animationPhase);
    }
    // Недостижимый код - вернём единичную матрицу.
    return glm::mat4();
}
