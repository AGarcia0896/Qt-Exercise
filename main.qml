import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Qt/QML Assessment - Main Window")

    Connections {
        target: Singleton
        onMaxValueChanged:  {
            console.log("Value from main: " + Singleton.maxValue)
        }

        onTimerValueChanged: {
            if (control.value <= control.to)
                control.value++
        }
    }

    ProgressBar {
        id: control
        anchors.centerIn: parent
        from: 0
        to: Singleton.maxValue !== 0 ? Singleton.maxValue : 100
        value: 0

        background: Rectangle {
            id: background
            implicitWidth: mainWindow.width * 0.8
            implicitHeight: 10
            color: "#E6E6E6"
            radius: 3
        }

        contentItem: Item {
            implicitWidth: mainWindow.width * 0.8
            implicitHeight: 8

            Rectangle {
                width: control.visualPosition * parent.width
                height: parent.height
                radius: 2
                color: "#17A81A"
            }
        }
    }

    Label {
        id: mProgress
        anchors.top: control.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: control.horizontalCenter
        text: control.value + "%"
        font.pointSize: 24
    }
}
