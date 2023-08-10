import QtQuick 2.3
import QtDataVisualization
import DataSource

Item {
	DataSource {
		id: dataSource
	}

    Connections {
        target: Simulation
        function onLastValueChanged() {
			dataSource.update(surfaceSeries)
        }
    }

	Surface3D {
		id: surfaceGraph
		anchors.fill: parent

		Surface3DSeries {
			id: surfaceSeries
			drawMode: Surface3DSeries.DrawSurface
			colorStyle: Theme3D.ColorStyleRangeGradient
			itemLabelFormat: "@xLabel, @zLabel: @yLabel"
			itemLabelVisible: false
		}

		shadowQuality: AbstractGraph3D.ShadowQualityNone
		renderingMode: AbstractGraph3D.RenderDirectToBackground

		axisX.min: 0.0
		axisX.max: 1.0
		axisY.min: 0.0
		axisY.max: 1.5
		axisZ.min: 0.0
		axisZ.max: 1.0
	}
}
