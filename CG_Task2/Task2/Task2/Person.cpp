#include "stdafx.h"
#include "Person.h"

static const glm::fvec3 CENTER_COLOR = { 1.f, 0.7f, 1.f };
static const glm::fvec3 PETAL_COLOR = { 0.1f, 0.7f, 1.f };


CPerson::~CPerson()
{
	DeleteList();
}

void CPerson::Setup(glm::fvec2 const &position)
{
	m_position = position;
	m_pArms = std::make_unique<CArms>();
	m_pArms->SetupArms({ 20.f, 10.f });
	m_pArms->SetCenterColor(CENTER_COLOR);
	m_pArms->SetPetalColor(PETAL_COLOR);
	m_pArms->SetPositionFirstArm({ 290.f, 290.f });
	m_pArms->SetPositionSecondArm({ 410.f, 290.f });

	m_pBody = std::make_unique<CBody>();
	m_pBody->SetRadius(60.f);
	m_pBody->SetPosition({ 350.f, 250.f });
	m_pBody->SetPetalColor(PETAL_COLOR);
	m_pBody->SetCenterColor(CENTER_COLOR);

	m_pEars = std::make_unique<CEars>();
	m_pEars->Setup(15.f, 50.f);
	m_pEars->SetPositionFirstEar({325.f, 160.f});
	m_pEars->SetPositionSecondEar({ 375.f, 160.f });
	m_pEars->SetPetalColor(PETAL_COLOR);
	m_pEars->SetCenterColor(CENTER_COLOR);

	m_pLegs = std::make_unique<CLegs>();
	m_pLegs->Setup(10.f, 8.f);
	m_pLegs->SetPetalColor(PETAL_COLOR);
	m_pLegs->SetCenterColor(CENTER_COLOR);
	m_pLegs->SetPositionFirstLeg({ 300.f, 300.f });
	m_pLegs->SetPositionSecondLeg({ 400.f, 300.f });
}




void CPerson::Draw()
{
	if (!m_displayList)
	{
		m_displayList = glGenLists(1);
		glNewList(m_displayList, GL_COMPILE);
		Redraw();
		glEndList();
	}
	glCallList(m_displayList);
}

void CPerson::DeleteList()
{
	if (m_displayList)
	{
		glDeleteLists(m_displayList, 1);
		m_displayList = 0;
	}
}

void CPerson::Redraw() const
{
	m_pBody->Draw();
	m_pArms->Draw();
	m_pEars->Draw();
	m_pLegs->Draw();
}