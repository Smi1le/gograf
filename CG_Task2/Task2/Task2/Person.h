#pragma once
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Arms.h"
#include "Body.h"
#include "Ears.h"
#include "Legs.h"


class CPerson
{
public:
	void Setup(glm::fvec2 const &position);
	void Draw();
	~CPerson();
private:
	void Redraw() const;
	void DeleteList();
private:
	mutable unsigned m_displayList = 0;
	glm::fvec2 m_position;
	std::unique_ptr<CArms> m_pArms;
	std::unique_ptr<CBody> m_pBody;
	std::unique_ptr<CEars> m_pEars;
	std::unique_ptr<CLegs> m_pLegs;
};