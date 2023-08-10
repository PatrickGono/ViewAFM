#include "DataSource.h"
#include <QDebug>
#include <algorithm>
#include <numbers>

DataSource::DataSource(QObject* parent) : QObject(parent)
{
	qRegisterMetaType<QSurface3DSeries*>();
	init(100, 100);
}

DataSource::~DataSource()
{
	clearData();
}

void DataSource::clearData()
{	
	qDeleteAll(m_data);
	m_data.clear();
}

void DataSource::init(int width, int length)
{
	int rowCount = width;
	int columnCount = length;

	m_data.reserve(rowCount * 2);
	for (int rowIndex = 0; rowIndex < 2 * rowCount; rowIndex++)
	{
		m_data.append(new QSurfaceDataRow(columnCount * 2));
	}

	for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
	{
		QSurfaceDataRow& row = *m_data[rowIndex];

		for (int columnIndex = 0; columnIndex < columnCount; columnIndex++)
		{
			QSurfaceDataItem& item = row[columnIndex];
			item.setPosition(QVector3D(rowIndex, 0.0, columnIndex));
		}
	}

	if (m_resetArray == nullptr)
	{
		return;
	}

	for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
	{
		QSurfaceDataRow& row = *(*m_resetArray)[rowIndex];

		for (int columnIndex = 0; columnIndex < columnCount; columnIndex++)
		{
			QSurfaceDataItem& item = row[columnIndex];
			item.setPosition(QVector3D(rowIndex, 0.0, columnIndex));
		}
	}

}

void DataSource::setWidthAndLength(int width, int length)
{
	if (!m_data.isEmpty())
	{
		clearData();
		qDebug() << "cleared data";
	}

	if (m_resetArray != nullptr)
	{
		// delete m_resetArray;
		// qDebug() << "deleted reset array";
	}

	init(width, length);
	qDebug() << "run init";
}

void DataSource::addData(int rowIndex, int columnIndex, double value)
{
	// need to swap y and z values
	QSurfaceDataRow& row = *m_data[rowIndex];
	QSurfaceDataItem& item = row[columnIndex];
	item.setPosition(QVector3D(rowIndex, value, columnIndex));

	//qDebug() << rowIndex << columnIndex;
	//m_filledColumnCount = std::max(m_filledColumnCount, columnIndex + 1);
}

void DataSource::update(QSurface3DSeries* series)
{
	if (series == nullptr || m_data.empty())
	{
		return;
	}

	int newRowCount = m_data.size();
	int newColumnCount = m_data.at(0)->size();

	if (series->dataProxy()->rowCount() != newRowCount || series->dataProxy()->columnCount() != newColumnCount)
	{
		if (m_resetArray == nullptr)
		{
			m_resetArray = new QSurfaceDataArray();
		}

		m_resetArray->reserve(newRowCount);
		for (int i = 0; i < newRowCount; i++)
		{
			m_resetArray->append(new QSurfaceDataRow(newColumnCount));
		}
	}

	for (int i = 0; i < newRowCount; ++i)
	{
		const QSurfaceDataRow& sourceRow = *(m_data.at(i));
		QSurfaceDataRow& row = *m_resetArray->at(i);
		std::copy(sourceRow.cbegin(), sourceRow.cend(), row.begin());
	}


	for (int i = 0; i < newRowCount; ++i)
	{
		const QSurfaceDataRow& row = *(m_resetArray->at(i));
		for (int j = 0; j < newColumnCount; j++)
		{
			//qDebug() << row.at(j).x() << " " << row.at(j).y() << " " << row.at(j).z();
		}
	}
	series->dataProxy()->resetArray(m_resetArray);
}
