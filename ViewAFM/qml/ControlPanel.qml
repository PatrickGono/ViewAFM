import QtQuick 2.3
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {
    id: controlPanel
    width: 200
    property var dataWidth: 100
    property var dataLength: 100

    ColumnLayout {
        spacing: 30
        Button {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            text: "START"
            onClicked: {
                Simulation.start()
            }
        }
        Button {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            text: "PAUSE"
            onClicked: {
                Simulation.pause()
            }
        }
        Button {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            text: "RESET"
            onClicked: {
                Simulation.reset()
            }
        }
        Slider {
            id: fpsSlider
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            from: 10
            to: 200
            value: 30
            onMoved: {
                Simulation.fps = fpsSlider.value
            }
        }
        Slider {
            id: widthSlider
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            from: 10
            to: 100
            value: 100
            onMoved: {
                controlPanel.dataWidth = widthSlider.value
            }
        }
        Slider {
            id: lengthSlider
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            from: 10
            to: 100
            value: 100
            onMoved: {
                controlPanel.dataLength = lengthSlider.value
            }
        }
    }
}
