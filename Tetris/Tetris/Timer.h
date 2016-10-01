#pragma once

class CTimer
{
public:
	CTimer() = default;
	void SetDeltaTime(float time);
	void SetToZero();
	float GetTime() const;
	bool CheckForExcess(float excess);
private:
	float m_time;
	bool m_isStart = false;
};


class CGenerator {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution;
	int min;
	int max;
public:
	CGenerator(int mean, int stddev, int min, int max) :
		distribution(mean, stddev), min(min), max(max)
	{}

	int operator ()() {
		while (true) {
			int number = this->distribution(generator);
			if (number >= this->min && number <= this->max)
				return number;
		}
	}
};