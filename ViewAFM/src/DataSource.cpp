#include "DataSource.h"
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
	int rowCount = 10;
	int columnCount = 12;

	for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
	{
		m_data.reserve(rowCount);
		for (int columnIndex = 0; columnIndex < columnCount; columnIndex++)
		{
			m_data.append(new QSurfaceDataRow(columnCount));
		}
	}

	for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
	{
		QSurfaceDataRow& row = *(m_data[rowIndex]);

		for (int columnIndex = 0; columnIndex < columnCount; columnIndex++)
		{
			float x = rowIndex / float(rowCount);
			float y = columnIndex / float(columnCount);
			float z = std::sin(std::numbers::pi * (x + y));
			z *= z;
			row[columnIndex] = QVector3D(x, y, z);
		}
	}
}

void DataSource::update(QSurface3DSeries* series)
{
	if (series == nullptr || m_data.empty())
	{
		return;
	}

	int newRowCount = m_data.size();
	int newColumnCount = m_data.at(0)->size();

	if (!m_resetArray || series->dataProxy()->rowCount() != newRowCount || series->dataProxy()->columnCount() != newColumnCount)
	{
		m_resetArray = new QSurfaceDataArray();
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
