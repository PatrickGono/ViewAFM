import QtQuick 2.3
import QtDataVisualization
import DataSource

Item {
	function setWidthAndLength(width, length) {
		surfaceGraph.axisX.max = width
		surfaceGraph.axisZ.max = length

		dataSource.setWidthAndLength(width, length)
	}

	DataSource {
		id: dataSource
	}

    Connections {
        target: Simulation
        function onLastValueChanged() {
			dataSource.addData(Simulation.lastValue3D.x, Simulation.lastValue3D.y, Simulation.lastValue3D.z)
			dataSource.update(surfaceSeries)
        }
    }

	Surface3D {
		id: surfaceGraph
		anchors.fill: parent

		Surface3DSeries {
			id: surfaceSeries
			drawMode: Surface3DSeries.DrawWireframe
			colorStyle: Theme3D.ColorStyleRangeGradient
			itemLabelFormat: "@xLabel, @zLabel: @yLabel"
			itemLabelVisible: false
		}

		shadowQuality: AbstractGraph3D.ShadowQualityNone
		renderingMode: AbstractGraph3D.RenderDirectToBackground

		axisX.min: 0.0
		axisX.max: 100.0
		axisY.min: -5.0
		axisY.max: 5.0
		axisZ.min: 0.0
		axisZ.max: 100.0
	}
}
