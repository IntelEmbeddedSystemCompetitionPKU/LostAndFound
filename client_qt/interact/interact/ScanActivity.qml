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
    MyThread {
        id: myThread
    }

    Timer {
        id: mytimer;
         interval: 500;
         running: false;
         repeat: true;
         onTriggered: {
             saveface()
         }
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
                myThread.setCommand("face")
                myThread.setArgs(uuid)
                myThread.startProcess()
                mytimer.stop()
                print("stop timer")
            }
        }
    }

    function saveface() {
        if(camera.imageCapture.ready) {
            print("save face")
            var savepath = myThread.getDir() + "fetch/"
            camera.imageCapture.captureToLocation(savepath)
        }
    }
    VideoOutput {
        id: videoOutput
        source: camera
        height: parent.height / 3 * 2
        width: parent.width / 3 * 2
        anchors.centerIn: parent
        focus: visible
        filters:[zxingFilter]
        Item {
            id: scanGroup
            anchors.fill: parent
            Rectangle {
                id: capturezone
                color: "red"
                opacity: 0.1
                height: videoOutput.height/2
                width: height
                anchors.centerIn: parent
            }
        }
    }

    Button {
        id: cancelbutton
        width: 300
        height: 200
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
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
        text: "扫描二维码"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
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
                print(tag)
                var kind = myThread.processQR(tag)
                if(kind == "fetch") {
                    scanGroup.visible = false

                    myThread.setCommand("get")
                    myThread.startProcess()
                    manager.popToPage("MainActivity.qml")
                    //mytimer.start()
                    //shotGroup.visible = true
                }
                else if(kind == "user") {
                    //myThread.uploadGetter
                    manager.popToPage("MainActivity.qml")
                }
                else if(kind == "mark") {
                    myThread.getNewUUID()
                    myThread.setCommand("savemark")
                    myThread.startProcess()
                    manager.popToPage("MainActivity.qml")
                }
                else{
                    resultLab.text = "无效二维码"
                }
            }
            tryHarder: false
        }
    }


    ////////////////////////////////////////////////
    Item {
        id: processingGroup
        anchors.fill: parent
        Text {
            id: processingText
            text: qsTr("处理中...")
            font.pixelSize: 25
        }
    }

///////////////////////////////////////////
    Item {
        id: shotGroup
        anchors.fill: parent

        Button {
            id: shotbutton
            width: 400
            height: 200
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                if(camera.imageCapture.ready) {
                    var savepath = myThread.getDir() + "fetch/"
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
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

    }
    Connections {
        target: myThread
        onFinish: {
            if(result == "true") {
                myThread.setCommand("get")
                myThread.setUUID(uuid)
                myThread.startProcess()
                manager.popToPage("MainActivity.qml")
            }
            else if(result == "false"){
                mytimer.start()
                print("start timer")
            }
    }


    Component.onCompleted: {
        processingGroup.visible = false
        scanGroup.visible = true
        shotGroup.visible = false
    }
}
}
