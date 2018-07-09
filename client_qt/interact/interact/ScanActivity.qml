import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import QZXing 2.3
import user.MyThread 1.0
import "."


Item{
    anchors.fill: parent
    property string uuid: ""
    property string dectag: "Nothing"
    property int scanstate:0
    MyThread {
        id: scanThread
    }

    Camera {
        id: camera

        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

        focus {
            focusMode: CameraFocus.FocusContinuous
            focusPointMode: CameraFocus.FocusPointAuto
        }
        imageCapture {
            onImageSaved: {
                scanThread.setCommand("face")
                scanThread.startProcess()
                shotGroup.visible = false
                processingGroup.visible = true
            }
        }
    }

    function saveface() {
        if(camera.imageCapture.ready) {
            print("save face")
            var savepath = scanThread.getDir() + "fetch/"
            camera.imageCapture.captureToLocation(savepath)
        }
    }

    VideoOutput {
        id: videoOutput
        source: camera

        anchors.fill: parent
        focus: visible
        filters:[zxingFilter]
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

    Text {
        id: resultLab
        font.pointSize: 15
        anchors.margins: 10
        text: "扫描二维码"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
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
                if(scanstate == 0) {
                var kind = scanThread.processQR(tag)
                if(kind == "fetch") {
                    scanGroup.visible = false
                    scanstate = 1
                    //mytimer.start()
                    scanGroup.visible = false
                    shotGroup.visible = true
                    resultLab.text = "请在框内留下完整面部信息 "
                }
                else if(kind == "user") {
                    print("in user")
                    scanThread.setCommand("picker")
                    scanThread.startProcess()
                    scanstate = 1
                    scanGroup.visible = false
                    processingText.text = "非常感谢"
                    processingGroup.visible = true
                    resultLab.text = ""
                }
                else if(kind == "mark") {
                    print("in mark")
                    scanThread.getNewUUID()
                    scanstate = 1
                    scanThread.setCommand("savemark")
                    scanThread.startProcess()
                    processingText.text = "请放入物品"
                    processingGroup.visible = true
                    scanGroup.visible = false
                }
                else{
                    resultLab.text = "无效二维码"
                }
                }
            }
            tryHarder: false
        }
    }


////////////////////////////////////////////////
    Item {
        id: processingGroup
        anchors.fill: parent
        Rectangle {
            anchors.centerIn: parent
            width: videoOutput.width / 3 * 2
            height: videoOutput.height / 3 * 2
            opacity: 0.7
            color: "gray"
            Text {
                anchors.centerIn: parent
                id: processingText
                text: qsTr("处理中...")
                font.pixelSize: 25
            }
        }
    }

///////////////////////////////////////////
    Item {
        id: shotGroup
        anchors.fill: parent
        Rectangle {
            anchors.centerIn: parent
            height: parent.height / 3 * 2
            width: height / 9 * 16
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
                    var savepath = scanThread.getDir() + "fetch/"
                    camera.imageCapture.captureToLocation(savepath)
                    shotGroup.visible = false
                    processingGroup.visible = true
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

    }
    Connections {
        target: scanThread
            onFinish: {
                print("onFinish " + result)
                if(result == "True") {
                    scanThread.setCommand("get")
                    scanThread.startProcess()
                    processingGroup.visible = true
                    processingText.text = "感谢使用"
                }
                else if(result == "False"){
                    shotGroup.visible = true
                    processingGroup.visible = false
                    resultLab.text = "照片无效,请重试"
                } else if(result == "pop") {
                    killTimer.start()
                }
        }
    }
    Component.onCompleted: {
        scanstate = 0
        processingGroup.visible = false
        scanGroup.visible = true
        shotGroup.visible = false
    }
    Timer {
        id: killTimer
              interval: 4000; running: false; repeat: false
              onTriggered: {
                  manager.popToPage("MainActivity.qml")
              }
          }
}
