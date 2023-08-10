import QtQuick 2.3
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {
    id: controlPanel
    width: 200
    property var dataWidth: 100
    property var dataLength: 100
    signal reset;

    ColumnLayout {
        spacing: 30
        Button {
            id: buttonStart
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            text: "START"
            onClicked: {
                Simulation.start()
            }
        }
        Button {
            id: buttonPause
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            text: "PAUSE"
            onClicked: {
                Simulation.pause()
            }
        }
        Button {
            id: buttonReset
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            text: "RESET"
            onClicked: {
                Simulation.reset()
                controlPanel.reset()
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
                Simulation.reset()
                Simulation.setWidthAndLength(widthSlider.value, lengthSlider.value)
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
                Simulation.reset()
                Simulation.setWidthAndLength(widthSlider.value, lengthSlider.value)
                controlPanel.dataLength = lengthSlider.value
            }
        }
    }
}
