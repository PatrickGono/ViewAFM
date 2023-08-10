#pragma once
#include "DataGenerator.h"

class DataGeneratorRidges : public DataGenerator
{
private:
	double m_period{0.0};

public:
	DataGeneratorRidges(unsigned int width, unsigned int height, double zAmp, double period);

	QPointF generateValue() override;
};

