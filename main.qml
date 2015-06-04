import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("The Travelling Salesman Problem")
    width: 1024
    height: 768
    minimumWidth: 1024
    minimumHeight: 768
    maximumWidth: 1024
    maximumHeight: 768
    visible: true

    FileDialog {
            id: fileDialog
            title: "Choose a file"
            nameFilters: [ "Data files (*.xlsx *.csv *.txt)", "All files (*)" ]
            selectedNameFilter: "All files (*)"
            onAccepted: {
                console.log("Accepted: " + fileUrls)
            }
            onRejected: { console.log("Rejected") }
        }

    Item {
        id: item
        property int count: 0
    }

    Connections {
        target: receiver
        onSendToModel: {
            theModel.addCity(count, x, y)
        }
        onSendToResults: {
            initdistance.text = dist;
            finaldistance.text = finaldist;
            iteration.text = iterations;
            time.text = extime;
        }
        onSendToText: {
            route.text = routes;
        }
    }

    MainForm {
        id: mainForm
        anchors.bottomMargin: 147
        anchors.rightMargin: 112
        anchors.fill: parent
    }

    Item {
        anchors.top: parent.top
        anchors.left: mainForm.right
        anchors.right: parent.right
        anchors.margins: 8

        SpinBox {
            id: temp
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
            id: coolrate
            x: 0
            y: 216
            width: 96
            height: 32
            decimals: 4
            stepSize: 0.0001
            style: SpinBoxStyle{}
            minimumValue: 0.0001
            maximumValue: 1
            value: 0.9992;
        }

        SpinBox {
            id: abstemp
            x: 0
            y: 138
            width: 96
            height: 32
            stepSize: 0.00001
            decimals: 5
            minimumValue: 0.00001
            value: 0.0001
            maximumValue: 100000
            style: SpinBoxStyle {
            }
        }
    }

    Item {
        anchors.rightMargin: 8
        anchors.bottomMargin: 10
        anchors.leftMargin: 8
        anchors.topMargin: 102
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
            onClicked: receiver.receiveFromQml1(temp.value, abstemp.value, coolrate.value)
        }
        Button {
            id: button3
            anchors.left: button2.right
            anchors.bottom: parent.bottom
            style: ButtonStyle{}
            text: "Import"
            onClicked: fileDialog.open()
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
        x: 920
        y: 38
        width: 96
        height: 25
        text: qsTr("Temperature")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Label {
        id: label2
        x: 920
        y: 194
        width: 96
        height: 25
        text: qsTr("Cooling Rate")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Label {
        id: label3
        x: 920
        y: 116
        width: 96
        height: 25
        text: qsTr("Abs Temperature")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    TextField {
        id: initdistance
        enabled: false
        x: 103
        y: 636
        width: 120
        height: 30
        text: qsTr("0")
        transformOrigin: Item.Center
        style: TextFieldStyle{}
    }

    TextField {
        id: finaldistance
        x: 103
        y: 680
        width: 120
        height: 30
        text: qsTr("0")
        enabled: false
        style: TextFieldStyle {
        }
    }

    Label {
        id: label4
        x: 8
        y: 636
        width: 89
        height: 30
        text: qsTr("Initial Distance")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        Label {
            id: label5
            x: 0
            y: 44
            width: 89
            height: 30
            text: qsTr("Final Distance")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Label {
        id: label6
        x: 249
        y: 636
        width: 89
        height: 30
        text: qsTr("Execution Time (s)")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        Label {
            id: label7
            x: 0
            y: 44
            width: 89
            height: 30
            text: qsTr("Iterations")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    TextField {
        id: time
        x: 344
        y: 636
        width: 120
        height: 30
        text: qsTr("0")
        enabled: false
        transformOrigin: Item.Center
        style: TextFieldStyle {
        }
    }

    TextField {
        id: iteration
        x: 344
        y: 680
        width: 120
        height: 30
        text: qsTr("0")
        enabled: false
        style: TextFieldStyle {
        }
    }

    TextArea {
        id: route
        x: 495
        y: 636
        width: 417
        height: 74
        textMargin: 8
        style: TextAreaStyle{}
        readOnly: true
    }
}
