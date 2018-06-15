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
    property int count: 0
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

    Text {
        id: title
        text: "敏感照片拍摄"
        font.pixelSize: 35
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
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
            camera.imageCapture.captureToLocation(savepath)
            count ++
            shotcount.text = "已拍摄" + qsTr(count) +"张"
            }
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
            id: shottext
            text: "拍摄"
            font.pixelSize: 35
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            id: shotcount
            text: "已拍摄0张"
            font.pixelSize: 20
            anchors.top: shottext.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Button {
        id: cancelbutton
        width: 200
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
            text: "取消"
            font.pixelSize: 20
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
                shotcount.text = "已拍摄0张"
                title.text = "次要照片拍摄"
            }
            else{
                manager.showPage("DescribeActivity.qml")
            }
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
            text: "完成"
            font.pixelSize: 20
        }
    }
    Component.onCompleted: {
        manager.setUUID()
        camstate = 0
    }
}
