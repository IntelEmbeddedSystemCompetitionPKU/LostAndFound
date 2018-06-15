import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import user.DataManager 1.0
import "."
Item{
    anchors.fill: parent
    Camera {
        id: camera
        imageCapture {
        }
    }

    Text {
        id: title
        text: "次要照片拍摄"
        font.pixelSize: 35
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Item {
        anchors.centerIn: parent
        height: parent.height / 2
        width: parent.width / 2
        VideoOutput {
            source: camera
            anchors.fill: parent
            focus: visible
        }
    }
    Button {
        id: shotbutton
        width: 400
        height: 200
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            var savepath = manager.getDir() + "HD/"
            camera.imageCapture.captureToLocation(savepath)
            textLabel.text = camera.imageCapture.capturedImagePath
        }
        style: ButtonStyle {
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 25
                border.width: control.activeFocus ? 2 : 1
                border.color: "#888"
                radius: 100
            }
        }
        Text {
            id: textLabel
        }
    }

    Button {
        id: cancelbutton
        width: 300
        height: 200
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        onClicked: {
            manager.popToPage("MainActivity.qml")
        }
        style: ButtonStyle {
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 25
                border.width: control.activeFocus ? 2 : 1
                border.color: "#888"
                radius: 100
            }
        }
        Text {
            anchors.centerIn: parent
            text: "Cancel"
        }
    }
    Button {
        id: donebutton
        width: 300
        height: 200
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        onClicked: {
            manager.showPage("DescribeActivity.qml")
        }
        style: ButtonStyle {
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 25
                border.width: control.activeFocus ? 2 : 1
                border.color: "#888"
                radius: 100
            }
        }
        Text {
            anchors.centerIn: parent
            text: "Finished"
        }
    }
}
