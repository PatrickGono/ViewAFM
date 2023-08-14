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
        RowLayout {
            Layout.preferredWidth: controlPanel.width - 20
            Label {
                Layout.preferredWidth: 50
                text: "FPS:"
            }
            Slider {
                id: sliderFps
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                from: 10
                to: 100
                value: 30
                onMoved: {
                    Simulation.fps = sliderFps.value
                }
            }
        }
        RowLayout {
            Layout.preferredWidth: controlPanel.width - 20
            Label {
                Layout.preferredWidth: 50
                text: "Width:"
            }
            Slider {
                id: widthSlider
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                from: 10
                to: 100
                value: 100
                onMoved: {
                    Simulation.reset()
                    Simulation.setWidthAndLength(widthSlider.value, lengthSlider.value)
                    controlPanel.dataWidth = widthSlider.value
                }
            }
        }
        RowLayout {
            Layout.preferredWidth: controlPanel.width - 20
            Label {
                Layout.preferredWidth: 50
                text: "Length:"
            }
            Slider {
                id: lengthSlider
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
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
}
