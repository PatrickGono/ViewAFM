import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts

Window {
    id: mainWindow
    visible: true
    width: 1024
    height: 768
    title: qsTr("ViewAFM")

    RowLayout {
        Column {
            Layout.preferredWidth: mainWindow.width - 200
            View2D {
                id: surfaceView
                anchors.margins: 20
                width: parent.width
                height: mainWindow.height - 300
            }
            View1D {
                id: profileView
                anchors.margins: 20
                width: parent.width
                height: 300
            }
        }

        ControlPanel {
            id: controlPanel
            Layout.preferredWidth: 200
        }

        Connections {
            target: controlPanel
            function onDataWidthChanged() {
                surfaceView.setWidthAndLength(controlPanel.dataWidth, controlPanel.dataLength);
            }
            function onDataLengthChanged() {
                surfaceView.setWidthAndLength(controlPanel.dataWidth, controlPanel.dataLength);
            }
        }
    }
}
