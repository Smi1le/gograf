#include "LogarithmicSpiral.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <cmath>

const double E = 2.718281828459;
const double PI = 3.1415926535897932;

void CLogarithmicSpiral::Draw()
{
	const float step = float(10 * PI / 360);
	glColor3f(1.f, 0.5f, 0.f);
	glLineWidth(2.f);
	glBegin(GL_LINE_STRIP);
	for (float angle = 0; angle <= float(10 * PI); angle += step)
	{
		double x = m_coefficientA * pow(E, double(m_coefficientB) * double(angle)) * cos(angle);
		double y = m_coefficientA * pow(E, double(m_coefficientB) * double(angle)) * sin(angle);
		glVertex2f(0.1f * float(x) + m_center.x, 0.1f * float(y) + m_center.y);
	}
	glEnd();
}


void CLogarithmicSpiral::Init(glm::fvec2 const &center, float a, float b, float scale)
{
	m_center = center;
	m_coefficientA = a;
	m_coefficientB = b;
	m_scale = scale;
}