#include "Simulation.h"
#include "DataGeneratorRidges.h"
#include <QDebug>

Simulation* Simulation::m_instance = nullptr;

Simulation* Simulation::getSimulation()
{
	if (m_instance == nullptr)
	{
		m_instance = new Simulation();
	}
	qDebug() << "getSimulation() called";
	return m_instance;
}

Simulation::Simulation(QObject *parent)
{
	qDebug() << "constructor called";

	m_dataGenerator = std::make_shared<DataGeneratorRidges>(DataGeneratorRidges(100, 100, 1.0, 22));

	m_timer.start(100);
	connect(&m_timer, &QTimer::timeout, this, &Simulation::update);
}

void Simulation::start()
{
	m_state = State::RUNNING;
}

void Simulation::pause()
{
	m_state = State::PAUSED;
}

void Simulation::reset()
{
	m_dataGenerator->reset();
	m_state = State::IDLE;
}

void Simulation::update()
{
	if (m_state == State::IDLE)
	{
		return;
	}

	if (m_state == State::PAUSED)
	{
		return;
	}

	if (m_state == State::RUNNING)
	{
		m_lastValue = m_dataGenerator->generateValue();
		emit lastValueChanged();
	}
}

QPointF Simulation::getLastValue() const
{
	return m_lastValue;
}

void Simulation::setFps(double fps)
{
	m_fps = fps;
	m_timer.setInterval(std::floor(1000.0 / m_fps));
	emit fpsChanged();
}

double Simulation::getFps() const
{
	return m_fps;
}
