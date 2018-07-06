import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import user.MyThread 1.0
import "."
Item{
    anchors.fill: parent
    property int camstate : 0
    property int count: 0
    MyThread {
        id: myThread
    }
    Camera {
        id: camera
          imageCapture {
             onImageSaved: {
                 shotcount.text = "已拍摄" + String(count) +"张"
                 myThread.setArgs(String(count))
                 myThread.startProcess()
                 shotgroup.visible = false
                 processGroup.visible = true
             }
        }
    }
    Item {
        anchors.fill: parent
        id: shotgroup
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
               savepath = myThread.getDir() + "ocr/"
            }
            else if(camstate === 1){
                savepath = myThread.getDir() + "HD/"
            }
            else{
                camstate = 0
            }
            camera.imageCapture.captureToLocation(savepath)
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
                count = 0
                thisConnections.enabled = false
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
    }
    Item {
        id: showgroup
        anchors.fill: parent
        Image {
            id: showImage
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            width: parent.width / 2 - 100
            anchors.margins: 20
        }
        TextEdit {
            id: showEdit
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            width: parent.width / 2 - 100
            anchors.margins: 20
        }
        Button {
            id: showbutton
            width: 300
            height: 200
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {//////////////set the information back if changed
                showgroup.visible = false
                shotgroup.visible = true
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
                text: "确认"
                font.pixelSize: 20
            }
        }

    }
    Item {
        id: processGroup
        anchors.fill: parent
        Text {
            id: processText
            anchors.centerIn: parent
            text: qsTr("处理中...")
            font.pixelSize: 25
        }
    }
    Connections {
        id: thisConnections
        target: myThread
        onFinish: {
            processGroup.visible = false
            showgroup.visible = true
            /////load image and text
        }
    }

    Component.onCompleted: {
        camstate = 0
        showgroup.visible = false
        processGroup.visible = false
        shotgroup.visible = true
        myThread.getNewUUID()
        myThread.setCommand(String("classify"))
    }
}
