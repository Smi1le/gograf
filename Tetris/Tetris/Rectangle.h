#pragma once

class CRectangle 
{
public:
	CRectangle(glm::fvec2 const &position = { 0.f, 0.f }, SSize const &size = {0.f, 0.f}, 
		glm::fvec3 const &color = { 0.f, 0.f, 0.f });
	void SetPosition(glm::fvec2 const &position);
	void SetSize(SSize const &size);
	void SetColor(glm::fvec3 const &color);
	glm::fvec2 GetPosition() const;
	glm::fvec3 GetColor() const;
	SSize GetSize() const;
	void Draw() const;
	void Tune(glm::fvec2 const &position, SSize const &size, glm::fvec3 const &color);
private:
	glm::fvec2 m_position;
	glm::fvec3 m_color;
	SSize m_size;
};