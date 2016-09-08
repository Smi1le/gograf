#pragma once
#include "DispatchEvent.h"
#include "CoordinateSystem.h"
#include "LogarithmicSpiral.h"

class CWindow : public CAbstractInputControlWindow
{
public:
    CWindow();

    // CAbstractWindow interface
protected:
    void OnUpdateWindow(float deltaSeconds) override;
    void OnDrawWindow(const glm::ivec2 &size) override;

private:
    void SetupView(const glm::ivec2 &size);
    float m_time = 0.f;
	CCoordinateSystem m_system;
	CLogarithmicSpiral m_spiral;
};
