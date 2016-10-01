#pragma once
#include "TetrisModel.h"
#include "TetrisView.h"
#include "Timer.h"
#include "DispatchEvent.h"


class CTetrisController : public IInputEventAcceptor
{
public:
	CTetrisController();
	void Draw();
	//void CreateNewShape();
	SHAPE_TYPE GetTypeNextShape() const;
	void OnKeyDown() override { this->KeyDown(); }
	void OnKeyUp() override { this->KeyUp(); }
	void OnKeyLeft() override { this->KeyLeft(); }
	void OnKeyRight() override { this->KeyRight(); }
	void LowerShape();
	bool CheckTimer(float time);
	void SetTime(float dt);
private:
	void KeyUp();
	void KeyDown();
	void KeyLeft();
	void KeyRight();
private:

	CTetrisModel m_model;
	CTetrisView m_view;
	SHAPE_TYPE m_typeNextShape;
	//mutable CGenerator m_randomGenerator;
	mutable boost::random::mt19937 m_random;
	boost::random::uniform_int_distribution<> m_norm;
	CTimer m_timer;
	bool m_isGameOver;
};