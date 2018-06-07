import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import "."
Item{
    anchors.fill: parent
    Camera {
        id: camera

        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

        exposure  {
            exposureCompensation: -1.0
            exposureMode: camera.ExposurePortrait
        }

        flash.mode: camera.FlashRedEyeReduction

        imageCapture {
            onImageCaptured: {
                photoPreview.source = preview
            }
        }
    }

    VideoOutput {
        source: camera
        anchors.left: parent.left
        width: parent.width / 2
        focus: visible
    }

    Image {
        anchors.right: parent.right
        width: parent.width / 2
        id: photoPreview
    }

    Button {
        id: shotbutton
        width: 400
        height: 200
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            camera.imageCapture.capture()
            textLabel.text = camera.imageCapture.capturedImagePath
        }
        Text {
            id: textLabel
        }

    }
}
