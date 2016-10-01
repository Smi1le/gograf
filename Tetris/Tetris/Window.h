#pragma once
#include "DispatchEvent.h"
#include <vector>
#include "Shape.h"
#include "TetrisController.h"

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
	CShape m_shape;
	CTetrisController m_controller;
	CTimer m_timer;
};
