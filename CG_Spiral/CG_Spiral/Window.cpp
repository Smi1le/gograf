#include "Window.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <iostream>

namespace
{
void FillRectangle(float x, float y, float width, float height)
{
	
	bool isMinSideWidth = width < height;
	float minSide = isMinSideWidth ? width : height;
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= int(minSide) * 2; ++i)
	{
		glm::fvec2 position;
		position = i % 2 == 0 ? (isMinSideWidth ? glm::fvec2(x + i / 2, y) : glm::fvec2(x, y + i / 2)) :
			(isMinSideWidth ? glm::fvec2(x + i / 2, y + height) : glm::fvec2(x + width, y + i / 2));
		glVertex2f(position.x, position.y);
	}
	glEnd();
}

void FillCoordinateSystem()
{
	
	float x = 382.5f;
	float y = 45;
	glm::fvec2 size = { 30.0f, 5.0f };
	glColor3f(0.0f, 0.0f, 1.0f);
	FillRectangle(395, 0, 5, 600);
	FillRectangle(0, 295, 800, 5);
	for (size_t i = 0; i != 11; ++i)
	{
		FillRectangle(x, y, size.x, size.y);
		y += 50;
	}
	x = 45;
	y = 282.5f;
	for (size_t i = 0; i != 15; ++i)
	{
		FillRectangle(x, y, size.y, size.x);
		x += 50;
	}
}

void FillLogarithmicSpiral(glm::ivec2 const &center)
{
	double a = 150;
	double b = 0.1;
	
}

}

CWindow::CWindow()
{
	m_system.Init({ 800, 600 });
	m_spiral.Init({ 400, 300 }, 150.f, 0.1f);
    SetBackgroundColor({0.f, 0.5f, 0.2f, 1.f});
}

void CWindow::OnUpdateWindow(float deltaSeconds)
{
    m_time += deltaSeconds;
}

void CWindow::OnDrawWindow(const glm::ivec2 &size)
{
    SetupView(size);

	//FillCoordinateSystem();

	m_system.Redraw();

	m_spiral.Draw();

	glColor3f(1.f, 0.75f, 0.84f);
	FillLogarithmicSpiral({ 400, 300 });
}

void CWindow::SetupView(const glm::ivec2 &size)
{
	// Матрица ортографического проецирования изображения в трёхмерном пространстве
	// из параллелипипеда с размером, равным (size.X x size.Y x 2).
    const glm::mat4 matrix = glm::ortho<float>(0, float(size.x), float(size.y), 0);
    glViewport(0, 0, size.x, size.y);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(matrix));
    glMatrixMode(GL_MODELVIEW);
}
