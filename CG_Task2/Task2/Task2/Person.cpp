#include "stdafx.h"
#include "Person.h"

static const glm::fvec3 CENTER_COLOR = { 1.f, 0.7f, 1.f };
static const glm::fvec3 PETAL_COLOR = { 0.1f, 0.7f, 1.f };
static const glm::fvec3 WHITE_COLOR = { 1.f, 1.f, 1.f };
static const glm::fvec3 PINK_COLOR = { 1.f, 0.5f, 1.f };

CPerson::~CPerson()
{
	DeleteList();
}

void CPerson::Setup(glm::fvec2 const &position)
{
	m_position = position;
	m_pArms.first = std::make_unique<CEllipse>();
	m_pArms.first->Setup(10.f, 20.f );
	m_pArms.first->SetCenterColor(PETAL_COLOR);
	m_pArms.first->SetPetalColor(PETAL_COLOR);
	m_pArms.first->SetPosition({ 290.f, 290.f });

	m_pArms.second = std::make_unique<CEllipse>();
	m_pArms.second->Setup(10.f, 20.f);
	m_pArms.second->SetCenterColor(PETAL_COLOR);
	m_pArms.second->SetPetalColor(PETAL_COLOR);\
	m_pArms.second->SetPosition({ 410.f, 290.f });

	m_pBody = std::make_unique<CEllipse>();
	m_pBody->Setup(60.f, 60.f);
	m_pBody->SetPosition({ 350.f, 250.f });
	m_pBody->SetColor(PETAL_COLOR);

	m_pEars.first = std::make_unique<CEllipse>();
	m_pEars.first->Setup(15.f, 45.f);
	m_pEars.first->SetPosition({325.f, 160.f });
	m_pEars.first->SetPetalColor(PETAL_COLOR);
	m_pEars.first->SetCenterColor(PETAL_COLOR);

	m_pEars.second = std::make_unique<CEllipse>();
	m_pEars.second->Setup(15.f, 45.f);
	m_pEars.second->SetPosition({ 375.f, 160.f });
	m_pEars.second->SetPetalColor(PETAL_COLOR);
	m_pEars.second->SetCenterColor(PETAL_COLOR);

	m_pLegs.first = std::make_unique<CEllipse>();
	m_pLegs.first->Setup(18.f, 16.f);
	m_pLegs.first->SetPetalColor(PETAL_COLOR);
	m_pLegs.first->SetCenterColor(CENTER_COLOR);
	m_pLegs.first->SetPosition({ 320.f, 310.f });
	
	m_pLegs.second = std::make_unique<CEllipse>();
	m_pLegs.second->Setup(18.f, 16.f);
	m_pLegs.second->SetPetalColor(PETAL_COLOR);
	m_pLegs.second->SetCenterColor(CENTER_COLOR);
	m_pLegs.second->SetPosition({ 380.f, 310.f });

	m_pEyes.first = std::make_unique<CEye>();
	m_pEyes.first->Setup(15.f, 20.f);
	m_pEyes.first->SetPetalColor(WHITE_COLOR);
	m_pEyes.first->SetCenterColor(WHITE_COLOR);
	m_pEyes.first->SetPosition({ 335.f, 232.f });
	m_pEyes.first->SetPositionPupil({340.f, 232.f});

	m_pEyes.second = std::make_unique<CEye>();
	m_pEyes.second->Setup(16.5f, 22.f);
	m_pEyes.second->SetPetalColor(WHITE_COLOR);
	m_pEyes.second->SetCenterColor(WHITE_COLOR);
	m_pEyes.second->SetPosition({ 365.f, 230.f });
	m_pEyes.second->SetPositionPupil({ 357.f, 232.f });

	m_pNose = std::make_unique<CEllipse>();
	m_pNose->Setup(7.f, 7.f);
	m_pNose->SetColor(PINK_COLOR);
	m_pNose->SetPosition({ 350.f, 250.f });

	m_pMouth = std::make_unique<CMouth>();
	m_pMouth->Setup();
	m_pMouth->SetColor({ 0.f, 0.f, 1.f });
	m_pMouth->SetPosition({ 350.f, 260.f });
	m_pMouth->SetSize({ 30.f, 18.f });
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

	m_pArms.first->Draw();
	m_pArms.second->Draw();
	
	m_pEars.first->Draw();
	m_pEars.second->Draw();
	
	m_pLegs.first->Draw();
	m_pLegs.second->Draw();
	
	m_pEyes.first->Draw();
	m_pEyes.second->Draw();

	m_pNose->Draw();

	m_pMouth->Draw();
}