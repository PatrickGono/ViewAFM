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
                anchors.margins: 20
                width: parent.width
                height: mainWindow.height - 300
            }
            View1D {
                anchors.margins: 20
                width: parent.width
                height: 300
            }
        }

        ControlPanel {
            Layout.preferredWidth: 200
        }
    }
}
