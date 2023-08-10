#include "DataGeneratorRidges.h"
#include <QDebug>
#include <numbers>
#include <cmath>

DataGeneratorRidges::DataGeneratorRidges(unsigned int width, unsigned int height, double zAmp, double period)
    : DataGenerator(width, height, zAmp), m_period(period)
{ 
}

QPointF DataGeneratorRidges::generateValue()
{
    double param = static_cast<double>(m_sampleCount % m_width) / m_period * std::numbers::pi;
    double prefactor = 4.0 * m_zAmplitude / std::numbers::pi;

    double height = prefactor * (std::sin(param) + 0.333333 * std::sin(3.0 * param) + 0.2 * std::sin(5.0 * param));
    double xPos = m_sampleCount % m_width;
    qDebug() << xPos << height;
    
    m_sampleCount++;
    return QPointF(xPos, height);
}
