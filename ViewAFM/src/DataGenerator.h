#pragma once
#include <QPoint>

class DataGenerator
{
protected:
	unsigned int m_width{0};
	unsigned int m_height{0};
	double m_zAmplitude{0.0};
	unsigned int m_sampleCount{0};

public:
	DataGenerator(unsigned int width, unsigned int height, double zAmp);
	
	virtual QPointF generateValue() = 0;
	virtual void reset();
};

