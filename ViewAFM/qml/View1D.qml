import QtQuick 2.3
import QtCharts

Item {
    property var startTime: Date.now()
    property var xRange: Simulation.xRange;
    property var yRange: Simulation.heightRange;

    Connections {
        target: Simulation
        function onLastValueChanged() {
            if (Simulation.lastValue.x == 0) {
                surfaceProfile.clear()
            }
            surfaceProfile.append(Simulation.lastValue.x, Simulation.lastValue.y)
        }
    }

    ChartView {
        id: view1D
        anchors.fill: parent

        ValueAxis {
            id: xAxis
            min: 0
            max: 100
            titleText: "x location (mm)"
        }

        ValueAxis {
            id: zAxis
            min: -2
            max: 2
            titleText: "height (um)"
        }

        LineSeries {
            id: surfaceProfile
            axisX: xAxis
            axisY: zAxis
        }
    }

}
