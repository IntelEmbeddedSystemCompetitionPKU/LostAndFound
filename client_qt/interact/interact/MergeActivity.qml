import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import user.MyThread 1.0
import QZXing 2.3
import "."
Item{
    anchors.fill: parent
    property int camstate : 0
    property string activityState: "shotInfo" //shotInfo, shotShape, shotFace, scan
    property int count: 0
    property int stage: 0
   property int processCount: 0
    property string basestring: "处理中"
    MyThread {
        id: myThread
    }
    Camera {
        deviceId: "/dev/video0"
        id: camera
        digitalZoom: 1.0
        viewfinder.resolution: Qt.size(1280, 720)
        focus {
            focusMode: CameraFocus.FocusContinuous
            focusPointMode: CameraFocus.FocusPointAuto
        }
          imageCapture {
             onImageSaved: {
                 count ++
                 if(activityState == "shotInfo") {
                     myThread.setCommand("classify")
                    myThread.setArgs(String(count))
                    myThread.startProcess()
                 }
                 /*else if(activityState == "shotShape"){
                     shotGroup.visible = true
                     processGroup.visible = false
                 }*/
                 else {
                     myThread.setCommand("face")
                     myThread.startProcess()
                 }
             }
        }
    }
    Camera {
        deviceId: "/dev/video1"
        id: faceCamera
        digitalZoom: 1.0
        viewfinder.resolution: Qt.size(1280, 720)
          imageCapture {
             onImageSaved: {
                 if(activityState == "shotShape"){
                     shotGroup.visible = true
                     processGroup.visible = false
                 }

             }
        }
    }
    Item {
        id: liveGroup
        anchors.fill: parent
        z:-3
        Text {
            anchors.centerIn: parent
            text: qsTr("初始化中...")
            font.pixelSize: 30
        }
        VideoOutput {
            id: videoOutput
            source: camera
            anchors.fill: parent
            focus: visible
            filters:[zxingFilter]
        }
        VideoOutput {
            id: faceOutput
            source: faceCamera
            anchors.fill: parent
            focus: visible
            visible: false
        }
    }

    Item {
        id: scanGroup
        anchors.fill: parent
        Rectangle {
            id: capturezone
            color: "red"
            opacity: 0.4
            height: videoOutput.height/2
            width: height
            anchors.centerIn: parent
        }
    }

    Item {
        id: shotGroup
         z: -1
        anchors.fill: parent
        Rectangle {
            anchors.centerIn: parent
            height: parent.height / 3 * 2
            width: height / 16 * 9
            opacity: 0.4
            color: "gray"
        }
        Button {
            id: shotbutton
            width: 400
            height: 200
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                if(camera.imageCapture.ready) {
                    var savepath = ""
                    if(activityState == "shotInfo") {
                       savepath = myThread.getDir() + "OCR/"
                        basestring = "处理中"
                    }
                    else if(activityState == "shotShape"){
                        savepath = myThread.getDir() + "HD/"
                        basestring = "保存中"
                    }
                    else if(activityState == "shotFace") {
                        savepath = myThread.getDir() + "fetch/"
                        basestring = "处理中"
                    }
                    print("save location is " + savepath)
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
                if(activityState == "shotInfo") {
                    activityState = "shotShape"
                    title.text = "补充信息拍摄"
                    count = 0
                }
                else{
                    myThread.setCommand("save")
                    myThread.startProcess()
                    processGroup.visible = true
                    basestring = "能留下身份二维码吗"
                    shotGroup.visible = false
                    title.text = ""
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
        anchors.fill: parent
        z: -1
        Rectangle {
            anchors.centerIn: parent
            width: videoOutput.width / 3 * 2
            height: videoOutput.height / 3 * 2
            opacity: 0.7
            color: "gray"
            Text {
                id: processText
                anchors.centerIn: parent
                font.pixelSize: 35
                text: qsTr("处理中...")
            }
        }
        Timer {
            id: addTimer
              interval: 500; running: true; repeat: true
              onTriggered: {
                  if(processCount == 0) {
                      processText.text = basestring + "."
                  }
                  else if(processCount == 1) {
                      processText.text = basestring + ".."
                  }
                  else if(processCount == 2) {
                      processText.text = basestring + "..."
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
        }
        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.left: processImage.right
            height: processImage.height
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
                    showGroup.visible = false
                    shotGroup.visible = true
                    liveGroup.visible = true
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
        text: "智能物品识别"
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
        anchors.margins: 10
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
            if(activityState == "scan") {
                if(result == "pop") {
                    killTimer.start()
                }
            }
            else if(activityState == "shotFace") {
                print("onFinish " + result)
                if(result == "True") {
                    myThread.setCommand("get")
                    myThread.startProcess()
                    processGroup.visible = true
                    basestring = "感谢使用"
                }
                else if(result == "False"){
                    shotGroup.visible = true
                    processGroup.visible = false
                    title.text = "照片无效,请重试"
                }
                else if(result == "pop") {
                    killTimer.start()
                }
            }
            else {
                if(result == "pop") {
                    jumpTimer.start()
                }
                else if(result != ""){
                    showEdit.text = result
                    processImage.source = "file://" + myThread.getDir() + "mask/" + String(count - 1) + ".jpg"
                    processGroup.visible = false
                    showGroup.visible = true
                    liveGroup.visible = false
                }
            }
        }
    }
    QZXingFilter {
        id: zxingFilter
        captureRect: {
            videoOutput.contentRect;
            videoOutput.sourceRect;
            return videoOutput.mapRectToSource(videoOutput.mapNormalizedRectToItem(Qt.rect(
                                                                 0.25,0.25,0.5,0.5)));
        }
        decoder {
            enabledDecoders: QZXing.DecoderFormat_QR_CODE

            onTagFound: {
                print("find tag: " + tag)
                if(activityState == "scan") {
                var kind = myThread.processQR(tag)
                    if(camstate == 0){
                        if(kind == "fetch") {
                            camstate = 1
                            activityState = "shotFace"
                            changeGroup()
                            title.text = "请在框内留下完整面部信息 "
                        }
                        else if(kind == "user") {
                            print("in user")
                            myThread.setCommand("picker")
                            myThread.startProcess()
                            basestring = "非常感谢"
                            scanGroup.visible = false
                            camstate = 1
                            processGroup.visible = true
                        }
                        else if(kind == "mark") {
                            print("in mark")
                            myThread.getNewUUID()
                            camstate = 1
                            myThread.setCommand("savemark")
                            myThread.startProcess()
                            basestring = "请放入物品"
                            processGroup.visible = true
                            scanGroup.visible = false
                        }
                        else{
                            title.text = "无效二维码"
                        }
                    }
                }
            }
            tryHarder: false
        }
    }
    Timer {
        id: jumpTimer
          interval: 2000; running: false; repeat: false
          onTriggered: {
              activityState = "scan"
              changeGroup()
          }
      }
    Timer {
        id: killTimer
              interval: 3000; running: false; repeat: false
              onTriggered: {
                  manager.popToPage("MainActivity.qml")
              }
          }

    function changeGroup(){
        if(activityState === "shotInfo") {
            scanGroup.visible = false
            shotGroup.visible = true
            showGroup.visible = false
            processGroup.visible = false
            title.text = "智能物品识别"
        }
        else if(activityState === "shotShape") {
            scanGroup.visible = false
            shotGroup.visible = true
            showGroup.visible = false
            processGroup.visible = false
        }
        else if(activityState === "shotFace"){
            videoOutput.visible = false
            faceOutput.visible = true
            scanGroup.visible = false
            shotGroup.visible = true
            showGroup.visible = false
            processGroup.visible = false
            title.text = "请在灰框内留下面部照片"
        }
        else {
            scanGroup.visible = true
            shotGroup.visible = false
            showGroup.visible = false
            processGroup.visible = false
            title.text = "请将二维码置于红框内"
        }
    }




    Component.onCompleted: {
        videoOutput.source = camera
        activityState =  manager.getIntent()
        if(activityState === "shotInfo") {
            myThread.getNewUUID()
        }
        changeGroup()
    }
}
