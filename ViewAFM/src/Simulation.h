#pragma once
#include <QObject>
#include <QTimer>
#include "DataGenerator.h"

class Simulation : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QPointF lastValue READ getLastValue NOTIFY lastValueChanged)
	Q_PROPERTY(QVector3D lastValue3D READ getLastValue3D NOTIFY lastValueChanged)
	Q_PROPERTY(double fps READ getFps WRITE setFps NOTIFY fpsChanged)
	Q_PROPERTY(int xRange READ getXRange NOTIFY xRangeChanged)

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
	QVector3D m_lastValue3D;
	double m_fps{30.0};
	int m_xRange{100};

	Simulation(QObject* parent = nullptr);

public:
	Q_INVOKABLE void start();
	Q_INVOKABLE void reset();
	Q_INVOKABLE void pause();
	Q_INVOKABLE void setWidthAndLength(int width, int length);

	static Simulation* getSimulation();
	void update();

	QPointF getLastValue() const;
	QVector3D getLastValue3D() const;

	double getFps() const;
	void setFps(double fps);

	int getXRange() const;

signals:
	void lastValueChanged();
	void fpsChanged();
	void xRangeChanged();
};

