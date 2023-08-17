#include "DataGenerator.h"
#include <QDebug>

DataGenerator::DataGenerator(int width, int length, double zAmp): m_width(width), m_length(length), m_zAmplitude(zAmp)
{
}

void DataGenerator::reset()
{
	m_sampleCount = 0;
}

void DataGenerator::setWidthAndLength(int width, int length)
{
	reset();
	m_width = width;
	m_length = length;
}
