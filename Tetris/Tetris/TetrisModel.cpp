#include "stdafx.h"
#include "TetrisModel.h"

CTetrisModel::CTetrisModel()
{
	m_cells.resize(20);
	for (auto &cell : m_cells)
	{
		cell.resize(10);
	}
	for (size_t i = 0; i != m_cells.size(); ++i)
	{
		glm::fvec2 position(100.f, SHAPE_SIZE.height * (m_cells.size() - i - 1));
		for (size_t j = 0; j != m_cells[i].size(); ++j)
		{
			m_cells[i][j] = SCellModel(position);
			position.x += SHAPE_SIZE.width;
		}
	}
}

int CTetrisModel::GetNumberOccupiedCells() const
{
	int result = 0;
	for (auto const & row : m_cells)
	{
		for (auto const &cell : row)
		{
			result += cell.isOccupied ? 1 : 0;
		}
	}
	return result;
}

void CTetrisModel::SetShape(std::vector<glm::fvec2> const & positions)
{
	for (auto const &pos : positions)
	{
		bool flag = false;
		for (auto &row : m_cells)
		{
			for (auto &cell : row)
			{
				if (cell.position == pos)
				{
					flag = true;
					cell.isOccupied = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
	}
}

void CTetrisModel::SetPositionsOccupiedCells(std::vector<glm::fvec2> const & cells)
{
	for (auto const &occupiedCell : cells)
	{
		bool flag = false;
		for (auto & row : m_cells)
		{
			for (auto &cell : row)
			{
				if (cell.position == occupiedCell)
				{
					cell.isOccupied = true;
					flag = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
	}
	glm::fvec2();
}

std::vector<std::vector<SCellModel>> CTetrisModel::GetDataPlayground() const
{
	return m_cells;
}
