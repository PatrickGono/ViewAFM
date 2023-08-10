#pragma once
#include <vector>

class SurfaceData
{
private:
	std::vector<double> m_data{};
	unsigned int m_width{0};
	unsigned int m_height{0};

public:
	SurfaceData(unsigned int width, unsigned int height);

	void clear();
	void append(double value);

	const std::vector<double>& getData() const;
	std::vector<double> getLastRow();
	double& operator()(int x, int y);
};

