#include "stdafx.h"
#include "Window.h"
//#include "Bodies.h"
//#include "Decorators.h"
#include <boost/range/algorithm/find_if.hpp>
#include <boost/range/adaptor/reversed.hpp>

namespace
{
	const glm::vec4 BLACK = {0, 0, 0, 1};
	const float MATERIAL_SHININESS = 30.f;
	const glm::vec4 FADED_WHITE_RGBA = {0.3f, 0.3f, 0.3f, 1.f};
	const glm::vec4 YELLOW_RGBA = {1, 1, 0, 1};
	const glm::vec3 SUNLIGHT_DIRECTION = {-1.f, 0.2f, 0.7f};
	const float CAMERA_INITIAL_ROTATION = 0;
	const float CAMERA_INITIAL_DISTANCE = 5.f;

	void SetupOpenGLState()
	{
		// включаем механизмы трёхмерного мира.
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CCW);
		//glCullFace(GL_FRONT);

		// включаем систему освещения
		glEnable(GL_LIGHTING);

		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	}

	float GetSincFromXY(float x, float y)
	{
		const float radius = std::hypotf(x, y);
		if (radius < std::numeric_limits<float>::epsilon())
		{
			return 1;
		}
		return sinf(radius) / radius;
	}
	float GetXMobiusStrip(float U, float V)
	{
		return (1.f + (V / 2.f * cosf(U / 2.f))) * cosf(U);
	}

	float GetYMobiusStrip(float U, float V)
	{
		return (1.f + (V / 2.f * cosf(U / 2.f))) * sinf(U);
	}

	float GetZMobiusStrip(float U, float V)
	{
		return V / 2.f * sinf(U / 2.f);
	}

}

CWindow::CWindow()
	: m_surface(GetXMobiusStrip, GetYMobiusStrip, GetZMobiusStrip)
    , m_camera(CAMERA_INITIAL_ROTATION, CAMERA_INITIAL_DISTANCE)
    , m_sunlight(GL_LIGHT0)
{
    SetBackgroundColor(BLACK);

    const glm::vec4 WHITE_RGBA = {1, 1, 1, 1};
    m_material.SetAmbient(YELLOW_RGBA);
    m_material.SetDiffuse(YELLOW_RGBA);
    m_material.SetSpecular(FADED_WHITE_RGBA);
    m_material.SetShininess(MATERIAL_SHININESS);

    m_surface.Tesselate({ 0.f, float(2 * M_PI) + 0.1f }, { -1, 1 }, 0.05f);

    m_sunlight.SetDirection(SUNLIGHT_DIRECTION);
    m_sunlight.SetDiffuse(WHITE_RGBA);
    m_sunlight.SetAmbient(0.1f * WHITE_RGBA);
    m_sunlight.SetSpecular(WHITE_RGBA);
}

void CWindow::OnWindowInit(const glm::ivec2 &size)
{
    (void)size;
    SetupOpenGLState();
}

void CWindow::OnUpdateWindow(float deltaSeconds)
{
    m_camera.Update(deltaSeconds);
    m_surface.Update(deltaSeconds);
}

void CWindow::OnDrawWindow(const glm::ivec2 &size)
{
    SetupView(size);
    m_sunlight.Setup();
    m_material.Setup();
    m_surface.Draw();
}

void CWindow::SetupView(const glm::ivec2 &size)
{
    glViewport(0, 0, size.x, size.y);

    // Матрица вида возвращается камерой и составляет
    // начальное значение матрицы GL_MODELVIEW.
    glLoadMatrixf(glm::value_ptr(m_camera.GetViewTransform()));

    // Матрица перспективного преобразования вычисляется функцией
    // glm::perspective, принимающей угол обзора, соотношение ширины
    // и высоты окна, расстояния до ближней и дальней плоскостей отсечения.
    const float fieldOfView = glm::radians(70.f);
    const float aspect = float(size.x) / float(size.y);
    const float zNear = 0.01f;
    const float zFar = 100.f;
    const glm::mat4 proj = glm::perspective(fieldOfView, aspect, zNear, zFar);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(proj));
    glMatrixMode(GL_MODELVIEW);
}

void CWindow::OnKeyDown(const SDL_KeyboardEvent &event)
{
    m_camera.OnKeyDown(event);
}

void CWindow::OnKeyUp(const SDL_KeyboardEvent &event)
{
	if (m_camera.OnKeyUp(event))
	{
		return;
	}
	if (event.keysym.sym == SDLK_SPACE)
	{
		m_surface.ChangeMode();
	}
}

void CWindow::OnDragBegin(const glm::vec2 &pos)
{
	m_camera.OnDragBegin(pos);
}
void CWindow::OnDragMotion(const glm::vec2 &pos)
{
	m_camera.OnDragMotion(pos);
}
void CWindow::OnDragEnd(const glm::vec2 &pos)
{
	m_camera.OnDragEnd(pos);
}
