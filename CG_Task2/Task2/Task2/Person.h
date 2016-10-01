#pragma once
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Eye.h"
#include "Mouth.h"


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
	std::pair<std::unique_ptr<CEllipse>, std::unique_ptr<CEllipse>> m_pArms;
	std::pair<std::unique_ptr<CEllipse>, std::unique_ptr<CEllipse>> m_pEars;
	std::pair<std::unique_ptr<CEllipse>, std::unique_ptr<CEllipse>> m_pLegs;
	std::pair<std::unique_ptr<CEye>, std::unique_ptr<CEye>> m_pEyes;
	std::unique_ptr<CEllipse> m_pBody;
	std::unique_ptr<CEllipse> m_pNose;
	std::unique_ptr<CMouth> m_pMouth; //TODO: убрать unique_ptr
};