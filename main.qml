import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("The Travelling Salesman Problem")
    width: 800
    height: 600
    minimumWidth: 800
    minimumHeight: 600
    maximumWidth: 800
    maximumHeight: 600
    visible: true

    Item {
        id: item
        property int count: 0
    }

    Connections {
        target: receiver
        onSendToModel: {
            theModel.addCity(count, x, y)
        }
    }

    MainForm {
        id: mainForm
        anchors.rightMargin: 112
        anchors.fill: parent
    }

    Item {
        anchors.top: parent.top
        anchors.left: mainForm.right
        anchors.right: parent.right
        anchors.margins: 8
    }

    Item {
        anchors.top: mainForm.bottom
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 8
        Button {
            id: button1
            focus: true
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            style: ButtonStyle{}
            text: "Close"
            onClicked: Qt.quit()
        }
        Button {
            id: button2
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            style: ButtonStyle{}
            text: "Run"
            onClicked: receiver.receiveFromQml()
        }
        Button {
            id: button3
            anchors.left: button2.right
            anchors.bottom: parent.bottom
            style: ButtonStyle{}
            text: "Import"
            onClicked: Qt.quit()
        }
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

    Text {
        id: text1
        x: 696
        y: 40
        width: 96
        height: 33
        text: qsTr("Text")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }

    TextInput {
        id: textInput1
        x: 696
        y: 80
        width: 96
        height: 33
        text: qsTr("Text Input")
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }
}
