import QtQuick 2.3
import QtDataVisualization

Item {
	width: 500
	Surface3D {
		id: surfaceGraph
		anchors.fill: parent

		Surface3DSeries {
			id: surfaceSeries
			drawMode: Surface3DSeries.DrawSurface
			colorStyle: Theme3D.ColorStyleRangeGradient

			ItemModelSurfaceDataProxy {
				//itemModel: surfaceData.model
			}
		}
	}
}
