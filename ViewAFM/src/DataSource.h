#pragma once
#include <QtDataVisualization/qsurface3dseries.h>
#include <QtQml/qqmlregistration.h>

class DataSource : public QObject
{
	Q_OBJECT
	QML_ELEMENT

public:
	DataSource(QObject* parent = nullptr);
    ~DataSource();

	Q_INVOKABLE void update(QSurface3DSeries* series);

private:
	void clearData();
	void init();

	QSurfaceDataArray m_data;
	int m_index = -1;
	QSurfaceDataArray* m_resetArray = nullptr;
};

