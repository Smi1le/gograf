#include "stdafx.h"
#include "TetrisModel.h"

CTetrisModel::CTetrisModel()
	: m_score(0)
	, m_level(1)
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

bool CTetrisModel::CheckPlayground()
{
	m_listForDelete.clear();
	size_t rowNumber = 0;
	for (auto const &row : m_cells)
	{
		size_t counter = 0;
		for (auto const &cell : row)
		{
			counter += cell.isOccupied ? 1 : 0;
		}
		if (counter == row.size())
		{
			m_listForDelete.push_back(rowNumber);
		}
		++rowNumber;
	}
	
	return m_listForDelete.size() > 0;
}

std::vector<size_t> CTetrisModel::GetListForDelete() const
{
	return m_listForDelete;
}


std::vector<std::vector<SCellModel>> CTetrisModel::GetDataPlayground() const
{
	return m_cells;
}

void CTetrisModel::CleanPlayground()
{
	ChangeScore();
	for (size_t i = m_listForDelete.size() - 1; i != -1; --i)
	{
		m_cells.erase(m_cells.begin() + m_listForDelete[i]);
	}

	RestructurePlayground();

	if (m_score % 100 == 0)
	{
		++m_level;
	}
}

int CTetrisModel::GetScore() const
{
	return m_score;
}

int CTetrisModel::GetLevel() const
{
	return m_level;
}

void CTetrisModel::ChangeScore()
{
	if (m_listForDelete.size() == 1)
	{
		m_score += 10;
	}
	else if (m_listForDelete.size() == 2)
	{
		m_score += 30;
	}
	else if (m_listForDelete.size() == 3)
	{
		m_score += 70;
	}
	else
	{
		m_score += 150;
	}
	//m_level = int(m_score + 100 / 100);
}

void CTetrisModel::RestructurePlayground()
{
	size_t numberRows = m_cells.size();
	m_cells.resize(20);
	for (size_t i = numberRows; i != m_cells.size(); ++i)
	{
		m_cells[i].resize(10);
		for (auto &cell : m_cells[i])
		{
			cell = SCellModel();
		}
	}


	for (size_t i = 0; i != m_cells.size(); ++i)
	{
		glm::fvec2 position(100.f, SHAPE_SIZE.height * (m_cells.size() - i - 1));
		for (size_t j = 0; j != m_cells[i].size(); ++j)
		{
			m_cells[i][j].position = position;
			position.x += SHAPE_SIZE.width;
		}
	}
}
