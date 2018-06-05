import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import "."
Item{
    anchors.fill: parent
    Item {
        id: finderButtonGroup
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        height: parent.height *2/3
        width: parent.width
        Button {
            id: findcard
            anchors.top: parent.top
            anchors.left: parent.left
            width: parent.width/2
            height: parent.height/2
            Text {
                anchors.centerIn: parent
                text: "Card"
                font.pixelSize: 20
            }
            onClicked: {
                manager.showPage("ShotInformationActivity.qml")
            }
        }
        Button {
            id: findwallet
            anchors.top: parent.top
            anchors.right: parent.right
            width: parent.width/2
            height: parent.height/2
            Text {
                anchors.centerIn: parent
                text: "Wallet"
                font.pixelSize: 20
            }
            onClicked: {
                manager.showPage("shotphoto.qml")
            }
        }
        Button {
            id: findcheap
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            width: parent.width/2
            height: parent.height/2
            Text {
                anchors.centerIn: parent
                text: "Cheap"
                font.pixelSize: 20
            }
        }
        Button {
            id: findexpensive
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            width: parent.width/2
            height: parent.height/2
            Text {
                anchors.centerIn: parent
                text: "Expensive"
                font.pixelSize: 20
            }
        }
    }

    Button {
        id: lostbutton
        anchors.bottom: parent.bottom
        anchors.top: finderButtonGroup.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        onClicked: manager.showPage("scanqrcode.qml")
    }

    Timer {
        interval: 500;
        running: true;
        repeat: true;
        onTriggered: {
            //timeLabel.text= (new Date().toLocaleTimeString(Qt.locale(),"hh:mm"));
        }
    }
}
