import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: item
    width: 640
    height: 480

    property int prevX
    property int prevY
    property var lineX: []
    property var lineY: []
    property var lineX1: []
    property var lineY1: []
    property bool test
    property bool clean
    property int count: 0
    property int lineWidth: 2
    property color drawColor: "black"

    Canvas {
        id: myCanvas
        anchors.fill: parent
        MouseArea {
            id:mousearea
            anchors.fill: parent
            onPressed: {
                prevX = mouseX
                prevY = mouseY
                receiver.receiveFromQml(count, prevX, prevY)
                myCanvas.requestPaint()
            }

        }

        Connections {
            target: receiver
            onSendToCanvas: {
                drawline(x, y, x1, y1)
            }
            onSendToReset: {
                drawdots(x, y)
            }

            onSendToClear: {
                reset()
            }

            function drawline(x, y, x1, y1) {
                var ctx = myCanvas.getContext('2d');
                ctx.beginPath();
                ctx.lineWidth = 2;
                ctx.moveTo(x, y);
                ctx.strokeStyle = "red"
                ctx.lineTo(x1, y1);
                ctx.stroke();
                myCanvas.requestPaint();
            }

            function drawdots(x, y) {
                var ctx = myCanvas.getContext('2d');
                ctx.beginPath();
                ctx.arc(x, y, 5, 0, Math.PI*2, true);
                ctx.closePath();
                ctx.fill();
            }

            function reset() {
                var ctx = myCanvas.getContext('2d');
                ctx.clearRect(0,0,myCanvas.width, myCanvas.height);
                prevX = 0;
                prevY = 0;
                myCanvas.requestPaint()
            }
        }

        onPaint: {
            draw(prevX, prevY);
            prevX = mousearea.mouseX;
            prevY = mousearea.mouseY;
        }



        function draw(x, y) {
            if (x > 0 & y > 0) {
                var ctx = getContext('2d');
                ctx.beginPath();
                ctx.arc(x, y, 5, 0, Math.PI*2, true);
                ctx.closePath();
                ctx.fill();
                count++;
            }
        }

    }
}
