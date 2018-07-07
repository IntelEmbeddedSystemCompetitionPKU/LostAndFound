import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import "."
Item{
    anchors.fill: parent
    Item {
        id: centeranch
        anchors.centerIn: parent
    }
    Rectangle{
        anchors.bottom: timerec.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: 0
        height: 200
        border.width: 0
        Text {
            id: maintitle
            text: "无人失物招领终端"
            anchors.centerIn: parent
            font.pixelSize: 100
        }
    }
    Rectangle{
        id: timerec
        anchors.bottom: centeranch.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: 0
        height: 200
        border.width: 0
        Text {
            id: timeboard
            color: "black"
            anchors.centerIn: parent
            text: qsTr("text")
            font.pixelSize: 100
        }
    }

    Item {
        id: finderButtonGroup
        anchors.top: centeranch.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        height: parent.height *2/3
        width: parent.width / 3 * 2
        Rectangle {
            id: divide
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            width: 2
            height: parent.height
        }

        Button {
            id: findButton
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: 40
            width: 300
            height: width
            style: ButtonStyle {
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 25
                    border.width: control.activeFocus ? 2 : 1
                    border.color: "#888"
                    radius: 150
                }
            }

            Text {
                anchors.centerIn: parent
                text: "无标记失物"
                font.pixelSize: 20
            }
            onClicked: {
                manager.showPage("ShotInformationActivity.qml")
            }
        }
        Button {
            id: lostbutton
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.margins: 40
            width: 300
            height: width
            style: ButtonStyle {
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 25
                    border.width: control.activeFocus ? 2 : 1
                    border.color: "#888"
                    radius: 150
                }
            }
            Text {
                anchors.centerIn: parent
                text: "扫描二维码"
                font.pixelSize: 20
            }
            onClicked: {
                manager.showPage("ScanActivity.qml")
            }
        }
    }



    Timer {
        interval: 500;
        running: true;
        repeat: true;
        onTriggered: {
            timeboard.text= (new Date().toLocaleTimeString(Qt.locale(),"hh:mm"));
        }
    }

    Component.onCompleted: {
        timeboard.text= (new Date().toLocaleTimeString(Qt.locale(),"hh:mm"));
    }
}
