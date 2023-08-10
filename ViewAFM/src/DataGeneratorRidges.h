#pragma once
#include "DataGenerator.h"

class DataGeneratorRidges : public DataGenerator
{
private:
	double m_period{0.0};
	double sineTerm(int n, double x) const;
	double firstNSineTerms(int n, double x) const;

public:
	DataGeneratorRidges(int width, int length, double zAmp, double period);

	QVector3D generateValue() override;
};

