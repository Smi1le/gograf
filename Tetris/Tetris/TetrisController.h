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
	void OnKeyP() override { this->KeyP(); }
	void OnKeySpace() override { this->StartGame(); }
	void LowerShape();
	bool CheckTimer(float time);
	void SetTime(float dt);
private:
	void KeyUp();
	void KeyDown();
	void KeyLeft();
	void KeyRight();
	void KeyP();
	void StartGame();
private:

	CTetrisModel m_model;
	CTetrisView m_view;
	SHAPE_TYPE m_typeNextShape;
	//mutable CGenerator m_randomGenerator;

	// TODO: use std::random,
	// move randomizer to separate class
	mutable CClampedNormalDistribution m_normalDistribution;
	mutable std::mt19937 m_random;
	CTimer m_timer;
	bool m_isGameOver = false;
	bool m_isGamePause = false;
	bool m_isGameStart = false;
};