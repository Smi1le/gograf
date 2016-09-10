#pragma once
#include "DispatchEvent.h"
#include "ParticleSystem.h"
#include "Person.h"
#include <vector>

class CWindow : public CAbstractInputControlWindow
{
public:
    CWindow();

protected:
    // CAbstractWindow interface
    void OnUpdateWindow(float deltaSeconds) override;
    void OnDrawWindow(const glm::ivec2 &size) override;

private:
    void SetupView(const glm::ivec2 &size);
	CPerson m_person;
    CParticleSystem m_system;
};
