import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import user.MyThread 1.0
Window {
    property int counter: 0
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Button {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        text: "Start Test"
        onClicked: {
            mythread.startTest(counter)
            counter += 1
            textbord.text = "Processing"
        }
    }
    Text {
        id: textbord
        text: qsTr("text")
    }
    MyThread {
        id: mythread
    }
    Connections {
        target:mythread
        onFinished: {
            textbord.text = result
        }
    }

}
