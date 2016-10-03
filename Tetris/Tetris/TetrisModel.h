#pragma once



class CTetrisModel
{
public:
	CTetrisModel();
	int GetNumberOccupiedCells() const;
	void SetShape(std::vector<glm::fvec2> const &positions);
	void SetPositionsOccupiedCells(std::vector<glm::fvec2> const &cells);
	bool CheckPlayground();
	std::vector<size_t> GetListForDelete() const;
	std::vector<std::vector<SCellModel>> GetDataPlayground() const;
	void CleanPlayground();
	int GetScore() const;
	int GetLevel() const;
private:
	void ChangeScore();
	void RestructurePlayground();
private:
	std::vector<std::vector<SCellModel>> m_cells;
	std::vector<size_t> m_listForDelete;
	int m_score;
	int m_level;
};