import QtQuick 2.3
import QtCharts

Item {
    id: profileView

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
            max: Simulation.xRange
            titleText: "x location"
        }

        ValueAxis {
            id: zAxis
            min: -2
            max: 2
            titleText: "height"
        }

        LineSeries {
            id: surfaceProfile
            axisX: xAxis
            axisY: zAxis
        }
    }
}
