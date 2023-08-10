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

	Q_INVOKABLE void addData(int rowIndex, int columnIndex, double height);
	Q_INVOKABLE void update(QSurface3DSeries* series);
	Q_INVOKABLE void setWidthAndLength(int width, int length);
	Q_INVOKABLE void clear(QSurface3DSeries* series);

	void init();

private:
	int m_width{100};
	int m_length{100};
	QSurfaceDataArray m_data;
	QSurfaceDataArray* m_resetArray = nullptr;

	void clearData();
	//int m_filledColumnCount{1};
};

