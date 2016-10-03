#include "stdafx.h"
#include "TetrisView.h"
#include <Windows.h>
#include <stdio.h>                        // Header File For Standard Input/Output    ( ADD )
#include <stdarg.h>   
#include <gl/GLU.h>
#include <GL/glut.h>
#include <GL/glew.h>
#include <GL/glsmap.h>
#include <string> 
#include <sstream>


namespace
{
	template <typename T>
	std::string toString(T val)
	{
		std::ostringstream oss;
		oss << val;
		return oss.str();
	}
}


/*#define _CRT_SECURE_NO_WARNINGS

HDC        hDC = NULL;  // Приватный контекст устройства GDI
HGLRC      hRC = NULL;  // Постоянный контекст рендеринга
HWND       hWnd = NULL; // Сохраняет дескриптор окна
HINSTANCE  hInstance; // Сохраняет экземпляр приложения

GLuint  base;                           // Base Display List For The Font Set
GLfloat cnt1;                           // 1st Counter Used To Move Text & For Coloring
GLfloat cnt2;                           // 2nd Counter Used To Move Text & For Coloring

bool    keys[256];                      // Array Used For The Keyboard Routine
bool    active = TRUE;                        // Window Active Flag Set To TRUE By Default
bool    fullscreen = TRUE;                    // Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);       // Declaration For WndProc
namespace
{
	
}

GLvoid BuildFont(GLvoid)								// Build Our Bitmap Font
{
	HFONT	font;										// Windows Font ID
	HFONT	oldfont;									// Used For Good House Keeping

	base = glGenLists(96);								// Storage For 96 Characters

	font = CreateFont(-24,							// Height Of Font
		0,								// Width Of Font
		0,								// Angle Of Escapement
		0,								// Orientation Angle
		FW_BOLD,						// Font Weight
		FALSE,							// Italic
		FALSE,							// Underline
		FALSE,							// Strikeout
		ANSI_CHARSET,					// Character Set Identifier
		OUT_TT_PRECIS,					// Output Precision
		CLIP_DEFAULT_PRECIS,			// Clipping Precision
		ANTIALIASED_QUALITY,			// Output Quality
		FF_DONTCARE | DEFAULT_PITCH,		// Family And Pitch
		"Courier New");					// Font Name

	oldfont = (HFONT)SelectObject(hDC, font);           // Selects The Font We Want
	wglUseFontBitmaps(hDC, 32, 96, base);				// Builds 96 Characters Starting At Character 32
	SelectObject(hDC, oldfont);							// Selects The Font We Want
	DeleteObject(font);									// Delete The Font
}


int InitGL(GLvoid)                      // All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);                // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);           // Black Background
	glClearDepth(1.0f);                 // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);                // Enables Depth Testing
	glDepthFunc(GL_LEQUAL);                 // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations

	BuildFont();                        // Build The Font

	return TRUE;                        // Initialization Went OK
}
*/

namespace 
{
	void RenderString(float x, float y, void *font, std::string const &text, glm::fvec3 const &rgb)
	{
		const char *c;

		glColor3f(rgb.x, rgb.y, rgb.z);
		glRasterPos2f(x, y);
		for (c = text.c_str(); *c != '\0'; c++) {
			glutBitmapCharacter(font, *c);
		}
	}
}

CTetrisView::CTetrisView(SSize const & size)
	: m_sizePlayground(size)
	, m_score(0)
	, m_level(1)
{
	m_positionPlayground = glm::fvec2(LEFT_SIDE, 0.f);
	m_playground.resize(20);
	for (auto &cell : m_playground)
	{
		cell.resize(10);
	}
	for (size_t i = 0; i != m_playground.size(); ++i)
	{
		glm::fvec2 position(LEFT_SIDE, SHAPE_SIZE.height * (m_playground.size() - i - 1));
		for (size_t j = 0; j != m_playground[i].size(); ++j)
		{
			m_playground[i][j] = SCellView(position);
			position.x += SHAPE_SIZE.width;
		}
	}
	//InitGL();
}

void CTetrisView::Draw()
{
	
	if (m_shape != nullptr)
	{
		this->DrawPlayground();
		m_shape->Draw();
		m_nextShape->Draw();
	}
	//TextDraw(std::string("Level " + m_level));
	//RenderString(300.f, 300.f, GLUT_BITMAP_TIMES_ROMAN_10, "Hello blyatb", { 1.f, 1.f, 1.f });

	RenderString(400.f, 150.f, GLUT_BITMAP_HELVETICA_18, std::string("Level " + toString(m_level)), { 0.f, 1.f, 0.3f });
	RenderString(400.f, 180.f, GLUT_BITMAP_HELVETICA_18, std::string("Score " + toString(m_score)), { 0.f, 1.f, 0.3f });
}

void CTetrisView::CreateShape(SHAPE_TYPE const & type)
{
	m_shape = !m_nextShape ? std::make_unique<CShape>(type) : std::move(m_nextShape);
	m_shape->SetPosition(FIRST_POSITION);
}

void CTetrisView::CreateNextShape(SHAPE_TYPE const & type)
{
	m_nextShape = std::make_unique<CShape>(type);
	m_nextShape->SetPosition({ LEFT_SIDE + SHAPE_SIZE.width * 10 + 40.f, 200.f });
	m_shape->SetPosition(FIRST_POSITION);
}

void CTetrisView::LowerShape()
{
	auto position = m_shape->GetPosition();
	m_shape->SetPosition({ position.x, position.y + SHAPE_SIZE.height });
}

void CTetrisView::UpperShape()
{
	auto position = m_shape->GetPosition();
	m_shape->SetPosition({ position.x, position.y - SHAPE_SIZE.height });

}

void CTetrisView::MoveShapeToLeft()
{
	auto position = m_shape->GetPosition();
	m_shape->SetPosition({ position.x - SHAPE_SIZE.width, position.y});
}

void CTetrisView::MoveShapeToRight()
{
	auto position = m_shape->GetPosition();
	m_shape->SetPosition({ position.x + SHAPE_SIZE.width, position.y });
}

void CTetrisView::AddShapeToPlayground()
{
	for (auto const &pos : m_shape->GetPositionsComponents())
	{
		bool flag = false;
		for (auto &row : m_playground)
		{
			for (auto &cell : row)
			{
				if (cell.position == pos)
				{
					flag = true;
					cell.color = m_shape->GetColor();
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
	}
	m_shape = std::move(m_nextShape);
}

void CTetrisView::ShapeMove()
{
	m_shape->Moves();
}

void CTetrisView::SetTime(float dt)
{
	m_timer.SetDeltaTime(dt);
}

void CTetrisView::OnKeyDown()
{
	if (m_timer.CheckForExcess(0.1f))
	{
		LowerShape();
		m_timer.SetToZero();
	}
}

void CTetrisView::RotateShape(ROTATE const &rotate)
{
	switch (rotate)
	{
	case ROTATE::right:
		m_shape->ChangeSide();
		break;
	case ROTATE::left:
		for (size_t i = 0; i != 3; ++i)
		{
			m_shape->ChangeSide();
		}
		break;
	}
}

void CTetrisView::CleanPlayground(std::vector<size_t> const &listForDelete)
{
	for (size_t i = listForDelete.size() - 1; i != -1; --i)
	{
		m_playground.erase(m_playground.begin() + listForDelete[i]);
	}
	RestructurePlayground();
}

std::vector<glm::fvec2> CTetrisView::GetPositionsComponentsShape() const
{
	return m_shape->GetPositionsComponents();
}

void CTetrisView::SetLevel(int level)
{
	m_level = level;
}

void CTetrisView::SetScore(int score)
{
	m_score = score;
}

void CTetrisView::TextDraw(std::string const & text, glm::fvec2 const &pos)
{
	RenderString(pos.x, pos.y, GLUT_BITMAP_TIMES_ROMAN_24, text.c_str(), { 0.7f, 0.7f, 1.f });
}

void CTetrisView::DrawPlayground() const
{
	glColor3f(BLUE.x, BLUE.y, BLUE.z);
	glRectf(m_positionPlayground.x - 20.f, m_positionPlayground.y, m_positionPlayground.x + m_sizePlayground.width + 20.f,
		m_positionPlayground.y + m_sizePlayground.height + 20.f);
	
	float border = SHAPE_SIZE.width / 10;
	for (auto const &row : m_playground)
	{
		for (auto const &cell : row)
		{
			glColor3f(0.f, 0.f, 0.f);
			glRectf(cell.position.x, cell.position.y, cell.position.x + SHAPE_SIZE.width,
				cell.position.y + SHAPE_SIZE.height);
			
			glColor3f(cell.color.x, cell.color.y, cell.color.z);
			glRectf(cell.position.x, cell.position.y, cell.position.x + SHAPE_SIZE.width - border,
				cell.position.y + SHAPE_SIZE.height - border);
		}
	}


}

void CTetrisView::RestructurePlayground()
{
	size_t numberRows = m_playground.size();
	m_playground.resize(20);
	for (size_t i = numberRows; i != m_playground.size(); ++i)
	{
		m_playground[i].resize(10);
		for (auto &cell : m_playground[i])
		{
			cell = SCellView();
		}
	}


	for (size_t i = 0; i != m_playground.size(); ++i)
	{
		glm::fvec2 position(100.f, SHAPE_SIZE.height * (m_playground.size() - i - 1));
		for (auto &cell : m_playground[i])
		{
			cell.position = position;
			position.x += SHAPE_SIZE.width;
		}
	}
}