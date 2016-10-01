#pragma once
#include "TetrisModel.h"
#include "TetrisView.h"
#include "Timer.h"


class CTetrisController
{
public:
	CTetrisController();
	void Draw();
	void CreateNewShape();
	SHAPE_TYPE GetTypeNextShape() const;
	void LowerShape();
private:
	CTetrisModel m_model;
	CTetrisView m_view;
	SHAPE_TYPE m_typeNextShape;
	//mutable CGenerator m_randomGenerator;
	mutable boost::random::mt19937 m_random;
	boost::random::uniform_int_distribution<> m_norm;
};