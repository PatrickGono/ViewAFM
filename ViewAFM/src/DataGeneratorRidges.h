#pragma once
#include "DataGenerator.h"

class DataGeneratorRidges : public DataGenerator
{
private:
	double m_period{0.0};

public:
	DataGeneratorRidges(int width, int length, double zAmp, double period);

	QVector3D generateValue() override;
};

