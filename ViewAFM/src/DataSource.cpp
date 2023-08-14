#include "DataSource.h"
#include <QDebug>
#include <algorithm>
#include <numbers>

DataSource::DataSource(QObject* parent) : QObject(parent)
{
	qRegisterMetaType<QSurface3DSeries*>();
	init();
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

void DataSource::init()
{
	int rowCount = m_width;
	int columnCount = m_length;

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
}

void DataSource::setWidthAndLength(int width, int length)
{
	clearData();

	qDeleteAll(*m_resetArray);
	m_resetArray->clear();

	m_width = width;
	m_length = length;

	init();
}

void DataSource::addData(int rowIndex, int columnIndex, double value)
{
	// need to swap y and z values
	QSurfaceDataRow& row = *m_data[rowIndex];
	QSurfaceDataItem& item = row[columnIndex];
	item.setPosition(QVector3D(rowIndex, value, columnIndex));
}

void DataSource::clear(QSurface3DSeries* series)
{	
	int rowCount = series->dataProxy()->rowCount();
	int columnCount = series->dataProxy()->rowCount();

	if (m_resetArray != nullptr)
	{
		qDeleteAll(*m_resetArray);
		m_resetArray->clear();
	}

	clearData();

	init();

	update(series);
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

	series->dataProxy()->resetArray(m_resetArray);
}
