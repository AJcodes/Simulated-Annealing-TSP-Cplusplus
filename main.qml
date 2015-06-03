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

        SpinBox {
            x: 0
            y: 60
            width: 96
            height: 32
            decimals: 5
            stepSize: 0.00001
            style: SpinBoxStyle{}
            minimumValue: 0.00001
            maximumValue: 100000
            value: 1
        }

        SpinBox {
            x: 0
            y: 145
            width: 96
            height: 32
            decimals: 4
            stepSize: 0.0001
            style: SpinBoxStyle{}
            minimumValue: 0.0001
            maximumValue: 1
            value: 0.9992;
        }
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

    Label {
        id: label1
        x: 696
        y: 37
        width: 96
        height: 25
        text: qsTr("Temperature")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Label {
        id: label2
        x: 696
        y: 122
        width: 96
        height: 25
        text: qsTr("Cooling Rate")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
