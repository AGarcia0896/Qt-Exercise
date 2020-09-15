import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Qt/QML Assessment - Second Window")

    Item {
        id: m
        anchors.fill: parent
        focus: true

        Keys.onPressed: {
            if (event.key === Qt.Key_R) {
                console.log("R pressed")
                Singleton.startProgress()
            }
            if (event.key === Qt.Key_S) {
                console.log("S pressed")
                Singleton.stopProgress()
            }
        }
    }

    Label {
        id: mLabel
        text: "Max Value:"
    }

    TextInput {
        id: mTextInput
        text: "0"
        anchors.left: mLabel.right
        anchors.leftMargin: 10
        onAccepted: {
            Singleton.maxValue = text
        }
    }

    ColumnLayout {
        id: mRadioButton
        anchors.top: mLabel.bottom
        anchors.topMargin: 10

        RadioButton {
            text: qsTr("RED")
            onClicked: {
                console.log("RED was pressed")
            }
        }
        RadioButton {
            text: qsTr("GREEN")
            onClicked: {
                console.log("GREEN was pressed")
            }
        }
        RadioButton {
            text: qsTr("BLUE")
            onClicked: {
                console.log("BLUE was pressed")
            }
        }
        RadioButton {
            text: qsTr("CYAN")
            onClicked: {
                console.log("CYAN was pressed")
            }
        }
    }
}
