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
	// m_distribution ������� ��� ���������:
	// `mean`, �.�. ��������� �������� � ������������ ���. ��������
	// `stddev`, �.�. ����������� ���������� (���������)
	// �� ������� ��� ��������� �� min/max.
	void param(float min, float max)
	{
		using param_type = std::normal_distribution<float>::param_type;
		const float mean = (min + max) / 2.f;
		const float stddev = (max - min) / 6.f;
		m_distribution.param(param_type(mean, stddev));
		m_min = min;
		m_max = max;
	}

	// ���������� ������������� ����� �������� �� ��� ��������� float
	// �� �� ����� ��������, ���������� �� ��������� [min, max]
	// �������������, ����� ��������� ����� 0.3% ��������.
	int operator ()(std::mt19937 &random) {
		while (true) {
			float number = m_distribution(random);
			if (number >= m_min && number <= m_max)
				return (int)number;
		}
	}
};