#include "stdafx.h"
#include "TetrisController.h"

namespace
{
	bool isCollision(std::vector<glm::fvec2> const &positions, float maxY)
	{
		for (auto const &pos : positions)
		{
			if (pos.y == maxY)
			{
				std::cout << "maxY = " << std::endl;
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

CTetrisController::CTetrisController()
	:m_view(CTetrisView({ SHAPE_SIZE.width * 10, SHAPE_SIZE.height * 20 }))
	, m_norm(boost::random::uniform_int_distribution<>(1, 7))
{
	m_view.CreateShape(GetTypeNextShape());
	m_view.CreateNextShape(GetTypeNextShape());

}

void CTetrisController::Draw()
{
	m_view.Draw();
}

SHAPE_TYPE CTetrisController::GetTypeNextShape() const
{
	int number = m_norm(m_random);//m_randomGenerator();
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
		std::cout << "yes " << std::endl;
	}
	
}
