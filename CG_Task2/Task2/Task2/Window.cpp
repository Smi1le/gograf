#include "stdafx.h"
#include "Window.h"

namespace
{
const glm::vec4 QUIET_GREEN = {0.f, 0.5f, 0.2f, 1.f};
}

CWindow::CWindow()
{
    SetBackgroundColor(QUIET_GREEN);
	m_person.Setup({ 300.f, 300.f });
}

void CWindow::OnUpdateWindow(float deltaSeconds)
{
}

void CWindow::OnDrawWindow(const glm::ivec2 &size)
{
    SetupView(size);
	m_person.Draw();
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
