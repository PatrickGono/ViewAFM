#pragma once
#include <QObject>
#include <QTimer>
#include "DataGenerator.h"

class Simulation : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QPointF lastValue READ getLastValue NOTIFY lastValueChanged)
	Q_PROPERTY(double fps READ getFps WRITE setFps NOTIFY fpsChanged)

	enum class State
	{
		RUNNING,
		IDLE,
		PAUSED
	};

private:
	static Simulation* m_instance;
	std::shared_ptr<DataGenerator> m_dataGenerator;
	State m_state{State::IDLE};
	QTimer m_timer;
	QPointF m_lastValue;
	double m_fps{30.0};

	Simulation(QObject* parent = nullptr);

public:
	Q_INVOKABLE void start();
	Q_INVOKABLE void reset();
	Q_INVOKABLE void pause();

	static Simulation* getSimulation();
	void update();
	QPointF getLastValue() const;
	double getFps() const;
	void setFps(double fps);

signals:
	void lastValueChanged();
	void fpsChanged();
};

