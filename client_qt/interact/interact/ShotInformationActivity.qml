import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import user.DataManager 1.0
import "."
Item{
    anchors.fill: parent
    property int camstate : 0
    Camera {
        id: camera
          imageCapture {
              onImageSaved:
                  textLabel.text = camera.imageCapture.capturedImagePath
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
            if(camera.imageCapture.ready) {
            var savepath
            if(camstate === 0) {
               savepath = manager.getDir() + "ocr/"
            }
            else if(camstate === 1){
                savepath = manager.getDir() + "HD/"
            }
            else{
                camstate = 0
            }
            camera.imageCapture.captureToLocation(savepath)}
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
            if(camstate === 0) {
                camstate = 1
            }
            else{
                manager.showPage("DescribeActivity.qml")
            }
        }
        Text {
            anchors.centerIn: parent
            text: "Finished"
        }
    }
    Component.onCompleted: {
        manager.setUUID()
        camstate = 0
    }
}
