#pragma once

class CMouth
{
public:
	CMouth() = default;
	void Setup(int petalCount = 40);
	void SetPosition(glm::fvec2 const &position);
	void SetSize(SSize const &size);
	void SetColor(glm::fvec3 const &color);
	void Draw();

private:
	glm::fvec2 m_center;
	glm::fvec3 m_color;
	SSize m_size;
	int m_petalCount;
};