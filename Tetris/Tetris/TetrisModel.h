#pragma once



class CTetrisModel
{
public:
	CTetrisModel();
	int GetNumberOccupiedCells() const;
	void SetShape(std::vector<glm::fvec2> const &positions);
	void SetPositionsOccupiedCells(std::vector<glm::fvec2> const &cells);
	std::vector<std::vector<SCellModel>> GetDataPlayground() const;
private:
	std::vector<std::vector<SCellModel>> m_cells;
};