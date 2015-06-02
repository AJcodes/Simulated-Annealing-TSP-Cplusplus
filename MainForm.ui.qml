import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

    TabView {
        id: tabView
        anchors.fill: parent
        anchors.leftMargin: 8
        anchors.topMargin: 8
        anchors.rightMargin: 8
        anchors.bottomMargin: 56
        style: TabViewStyle{} //Commented out to see if works when QT_QUICK_CONTROLS_STYLE=Breeze is set
        frameVisible: true
        Component.onCompleted: {
            addTab("Chart", page1)
            addTab("Cities", page2)
        }
        Component {
            id: page1
            CanvasForm {}
        }
        Component {
            id: page2
            TableForm {}
        }
    }


