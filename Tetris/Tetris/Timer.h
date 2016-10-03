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


class CClampedNormalDistribution
{
	std::normal_distribution<float> m_distribution;
	float m_min = 0.f;
	float m_max = 0.f;
public:
	// m_distribution требует два параметра:
	// `mean`, т.е. медианное значение и одновременно мат. ожидание
	// `stddev`, т.е. стандартное отклонение (дисперсию)
	// мы выводим эти параметры из min/max.
	void param(float min, float max)
	{
		using param_type = std::normal_distribution<float>::param_type;
		const float mean = (min + max) / 2.f;
		const float stddev = (max - min) / 6.f;
		m_distribution.param(param_type(mean, stddev));
		m_min = min;
		m_max = max;
	}

	// Ќормальное распределение выдаЄт значени€ на всЄм диапазоне float
	// Ќо мы режем значени€, выпадающие из диапазона [min, max]
	// —татистически, будет выброшено около 0.3% значений.
	int operator ()(std::mt19937 &random) {
		while (true) {
			float number = m_distribution(random);
			if (number >= m_min && number <= m_max)
				return (int)number;
		}
	}
};