#pragma once
#include <QPoint>
#include <QVector3D>

class DataGenerator
{
protected:
	int m_width{0};
	int m_length{0};
	double m_zAmplitude{0.0};
	unsigned int m_sampleCount{0};

public:
	DataGenerator(int width, int length, double zAmp);
	
	virtual QVector3D generateValue() = 0;
	virtual void reset();
	virtual void setWidthAndLength(int width, int length);
};

