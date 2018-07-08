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
                 count ++
                 if(camstate == 0) {
                     myThread.setCommand("classify")
                    myThread.setArgs(String(count))
                    myThread.startProcess()
                    stage = 1
                    shottext.text = "确认"
                     showEdit.text = "处理中..."
                 }
                 else {
                     showEdit.text = "已保存"
                 }
             }
        }
    }
    Item {
        id: shotGroup
         z: -1
        anchors.fill: parent
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
                       savepath = myThread.getDir() + "OCR/"
                    }
                    else if(camstate === 1){
                        savepath = myThread.getDir() + "HD/"
                    }
                    camera.imageCapture.captureToLocation(savepath)
                    shotGroup.visible = false
                    processGroup.visible = true
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
                anchors.centerIn: parent
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
    }

    Item {
        id: processGroup
         z: -1
        property int processCount: 0
        Text {
            id: processText
            anchors.centerIn: parent
            font.pixelSize: 35
            text: qsTr("处理中...")
        }
        Timer {
              interval: 500; running: true; repeat: true
              onTriggered: {
                  if(processCount == 0) {
                      processText.text = "处理中."
                  }
                  else if(processCount == 1) {
                      processText.text = "处理中.."
                  }
                  else if(processCount == 2) {
                      processText.text = "处理中..."
                  }
                  processCount ++
                  if(processCount > 3) {
                      processCount = 0
                  }
              }
          }
    }

    Item {
        id: showGroup
        anchors.fill: parent
        z: -1
        Image {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            height: parent.height / 2
            width: parent.width / 2
            id: processImage
            visible: false
        }
        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.left: imagegroup.right
            height: imagegroup.height
            anchors.margins: 20
            color: "gray"
            TextEdit {
                anchors.margins: 5
                id: showEdit
                anchors.fill: parent
                font.pixelSize: 30
            }
        }
        Button {
            id: confirmbutton
            width: 400
            height: 200
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 15
            onClicked: {
                    myThread.setCommand("refresh")
                    myThread.setArgs(count)
                    myThread.addDesc(showEdit.text)
                    myThread.startProcess()
                showGroup.visible = False
                shotGroup.visible = True
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
                id: confirmtext
                text: "确认"
                font.pixelSize: 35
                anchors.centerIn: parent
            }
        }
    }



    Text {
        id: title
        text: "敏感照片拍摄"
        font.pixelSize: 35
        anchors.margins: 10
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
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
    Connections {
        id: thisConnections
        target: myThread
        onFinish: {
            showEdit.text = result
            processImage.source = "file://" + myThread.getDir() + "mask/" + String(count - 1) + ".jpg"
            processGroup.visible = false
            showGroup.visible = true
        }
    }

    Component.onCompleted: {
        camstate = 0
        myThread.getNewUUID()
        myThread.setCommand(String("classify"))
    }
}
