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
    property int stage: 0
    MyThread {
        id: myThread
    }
    Camera {
        id: camera
        focus {
            focusMode: CameraFocus.FocusContinuous
            focusPointMode: CameraFocus.FocusPointAuto
        }
          imageCapture {
             onImageSaved: {
                 shotcount.text = "已拍摄" + String(count) +"张"
                 count ++
                 if(camstate == 0) {
                     myThread.setCommand("classify")
                    myThread.setArgs(String(count))
                    myThread.startProcess()
                    stage = 1
                    shottext.text = "确认"
                     showEdit.text = "处理中..."
                 }
             }
        }
    }
    Button {
        id: shotbutton
        width: 400
        height: 200
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            if(stage == 0) {
                if(camera.imageCapture.ready) {
                var savepath
                if(camstate === 0) {
                   savepath = myThread.getDir() + "OCR/"
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
            else {
                stage = 0
                shottext.text = "拍摄"
                myThread.setCommand("refresh")
                myThread.setArgs(count)
                myThread.addDesc(showEdit.text)
                myThread.startProcess()
                processImage.visible = false
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
                myThread.setCommand("save")
                myThread.startProcess()
                manager.showPage("ScanActivity.qml")
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
    Text {
        id: title
        text: "敏感照片拍摄"
        font.pixelSize: 35
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Item {
        id: imagegroup
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        height: parent.height / 2
        width: parent.width / 2
        Text {
            anchors.centerIn: parent
            text: qsTr("初始化中...")
            font.pixelSize: 30
        }
        VideoOutput {
            id: liveImage
            source: camera
            anchors.fill: parent
            focus: visible
        }
        Image {
            anchors.fill: parent
            id: processImage
            visible: false
        }
    }

    Rectangle {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.left: imagegroup.right
        height: imagegroup.height
        anchors.margins: 20
        color: "gray"
        TextEdit {
            id: showEdit
            anchors.fill: parent
            font.pixelSize: 30
        }
    }

    Connections {
        id: thisConnections
        target: myThread
        onFinish: {
            //processImage.source = myThread.getDir() + "mask/" + String(count) + ".jpg"
            showEdit.text = result
            processImage.visible = true

        }
    }

    Component.onCompleted: {
        camstate = 0
        myThread.getNewUUID()
        myThread.setCommand(String("classify"))
    }
}
