#include "SurfaceData.h"

SurfaceData::SurfaceData(unsigned int width, unsigned int height): m_width(width), m_height(height)
{
	m_data.reserve(m_width * m_height);
}

void SurfaceData::clear()
{
	m_data.clear();
}

void SurfaceData::append(double value)
{
	m_data.push_back(value);
}

const std::vector<double>& SurfaceData::getData() const
{
	return m_data;
}

std::vector<double> SurfaceData::getLastRow()
{
	if (m_data.empty())
	{
		return std::vector<double>();
	}

	int currentLength = m_data.size();
	int fullRowCount = static_cast<int>(currentLength / m_width);
	std::vector<double> lastRow = {m_data.begin() + fullRowCount * m_width, m_data.end()};
	return lastRow;
}

double& SurfaceData::operator()(int x, int y)
{
	return m_data.at(x * m_width + y);
}
