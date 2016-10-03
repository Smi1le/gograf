#include "stdafx.h"
#include "TetrisController.h"

namespace
{
	bool isCollision(std::vector<glm::fvec2> const &positions, float max, int side = 0)
	{
		for (auto const &pos : positions)
		{
			if (side == 0 && pos.y == max)
			{
				return true;
			}
			else if (side == 1 && pos.x == max)
			{
				return true;
			}
		}
		return false;
	}
	
	bool isCollision(std::vector<glm::fvec2> const &firstPositions, std::vector<std::vector<SCellModel>> const &secondPositions)
	{
		for (auto const pos1 : firstPositions)
		{
			for (auto const &pos2 : secondPositions)
			{
				for (auto const &cell : pos2)
				{
					if (pos1 == cell.position && cell.isOccupied)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
}

void CTetrisController::KeyP() 
{
	m_isGamePause = !m_isGamePause;
}
void CTetrisController::StartGame()
{
	m_view.CreateShape(GetTypeNextShape());
	m_view.CreateNextShape(GetTypeNextShape());
	m_isGameStart = true;
}

CTetrisController::CTetrisController()
	:m_view(CTetrisView({ SHAPE_SIZE.width * 10, SHAPE_SIZE.height * 20 }))
	, m_isGameOver(false)
{
	std::random_device rd;
	m_random.seed(rd());
	
	m_normalDistribution.param(0.0f, 7.5f);


}

void CTetrisController::Draw()
{
	m_view.Draw();
	if (m_isGameStart)
	{
		if (m_isGameOver)
		{
			m_view.TextDraw(std::string("Game Over"), { 300.f, 300.f });
		}
		if (m_isGamePause)
		{
			m_view.TextDraw(std::string("Game is pause"), { 300.f, 300.f });
		}
	}
	else
	{
		m_view.TextDraw(std::string("PLEASE ENTER RIGHT CTRL FOR START GAME"), { 200.f, 300.f });
	}
}

SHAPE_TYPE CTetrisController::GetTypeNextShape() const
{
	int number = m_normalDistribution(m_random);//m_randomGenerator(); 
	if (number == 1)
	{
		return SHAPE_TYPE::first;
	}
	else if (number == 2)
	{
		return SHAPE_TYPE::second;
	}
	else if (number == 3)
	{
		return SHAPE_TYPE::third;
	}
	else if (number == 4)
	{
		return SHAPE_TYPE::fourth;
	}
	else if (number == 5)
	{
		return SHAPE_TYPE::fifth;
	}
	else if (number == 6)
	{
		return SHAPE_TYPE::sixth;
	}
	else
	{
		return SHAPE_TYPE::seventh;
	}
}

void CTetrisController::LowerShape()
{
	if (!m_isGameOver && !m_isGamePause && m_isGameStart)
	{
		m_view.LowerShape();
		auto shapePositions = m_view.GetPositionsComponentsShape();
		auto maxYForShape = SHAPE_SIZE.height * 20;
		if (isCollision(shapePositions, maxYForShape) || isCollision(shapePositions, m_model.GetDataPlayground()))
		{
			m_view.UpperShape();
			shapePositions = m_view.GetPositionsComponentsShape();
			m_model.SetShape(shapePositions);
			m_view.AddShapeToPlayground();
			m_view.CreateNextShape(GetTypeNextShape());
			if (m_model.CheckPlayground())
			{
				m_model.CleanPlayground();
				m_view.CleanPlayground(m_model.GetListForDelete());
				m_view.SetLevel(m_model.GetLevel());
				m_view.SetScore(m_model.GetScore());
			}
			else if (isCollision(shapePositions, FIRST_POSITION.y))
			{
				m_isGameOver = true;
			}
		}
	}
}

bool CTetrisController::CheckTimer(float time)
{
	if (m_timer.CheckForExcess(time))
	{
		m_timer.SetToZero();
		return true;
	}
	return false;
}

void CTetrisController::SetTime(float dt)
{
	m_timer.SetDeltaTime(dt);
	m_view.SetTime(dt);
}

void CTetrisController::KeyUp()
{
	if (!m_isGameOver || !m_isGamePause)
	{
		m_view.RotateShape(ROTATE::right);
		auto shapePositions = m_view.GetPositionsComponentsShape();
		auto minXForShape = LEFT_SIDE - SHAPE_SIZE.width;
		if (isCollision(shapePositions, minXForShape, 1) || isCollision(shapePositions, m_model.GetDataPlayground())
			|| isCollision(shapePositions, LEFT_SIDE + SHAPE_SIZE.width * 10, 1))
		{
			m_view.RotateShape(ROTATE::left);
		}
	}
}

void CTetrisController::KeyDown()
{
	LowerShape();
}

void CTetrisController::KeyLeft()
{
	if (!m_isGameOver || !m_isGamePause)
	{
		m_view.MoveShapeToLeft();
		auto shapePositions = m_view.GetPositionsComponentsShape();
		auto minXForShape = LEFT_SIDE - SHAPE_SIZE.width;
		if (isCollision(shapePositions, minXForShape, 1) || isCollision(shapePositions, m_model.GetDataPlayground())
			|| isCollision(shapePositions, LEFT_SIDE + SHAPE_SIZE.width * 10, 1))
		{
			m_view.MoveShapeToRight();
		}
	}
}

void CTetrisController::KeyRight()
{
	if (!m_isGameOver || !m_isGamePause)
	{
		m_view.MoveShapeToRight();
		auto shapePositions = m_view.GetPositionsComponentsShape();
		auto minXForShape = LEFT_SIDE + SHAPE_SIZE.width * 10;
		if (isCollision(shapePositions, minXForShape, 1) || isCollision(shapePositions, m_model.GetDataPlayground()))
			//|| isCollision(shapePositions, LEFT_SIDE + SHAPE_SIZE.width * 10, 1))
		{
			m_view.MoveShapeToLeft();
		}
	}
}
