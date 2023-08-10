import QtQuick 2.3
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {
    id: controlPanel
    width: 200
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
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: controlPanel.width - 20
            id: fpsSlider
            from: 10
            to: 200
            value: 30
            onMoved: {
                Simulation.fps = fpsSlider.value
            }
        }
    }
}
