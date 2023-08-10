#include "DataGenerator.h"
#include <QDebug>

DataGenerator::DataGenerator(unsigned int width, unsigned int height, double zAmp): m_width(width), m_height(height), m_zAmplitude(zAmp)
{
}

void DataGenerator::reset()
{
	m_sampleCount = 0;
	qDebug() << "reset";
}
