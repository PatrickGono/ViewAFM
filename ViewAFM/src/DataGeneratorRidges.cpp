#include "DataGeneratorRidges.h"
#include <QDebug>
#include <numbers>
#include <cmath>

DataGeneratorRidges::DataGeneratorRidges(int width, int height, double zAmp, double period)
    : DataGenerator(width, height, zAmp), m_period(period)
{ 
}

QVector3D DataGeneratorRidges::generateValue()
{
    double param = static_cast<double>(m_sampleCount % m_width) / m_period * std::numbers::pi;
    double prefactor = 4.0 * m_zAmplitude / std::numbers::pi;

    double height = prefactor * firstNSineTerms(4, param);
    int xPos = m_sampleCount % m_width;
    int yPos = std::floor(m_sampleCount / m_width);
    m_sampleCount++;
    return QVector3D(xPos, yPos, height);
}

double DataGeneratorRidges::sineTerm(int n, double x) const
{
    return 1.0 / n * std::sin(n * x);
}

double DataGeneratorRidges::firstNSineTerms(int n, double x) const
{
    double sum{0.0};
    for (int termIndex = 0; termIndex < n; termIndex++)
    {
        int i = 1 + 2 * termIndex;
        sum += sineTerm(i, x);
    }

    return sum;
}
