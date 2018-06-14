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
        Text {
            anchors.centerIn: parent
            text: "Finished"
        }
    }
    Component.onCompleted: {

    }

}
