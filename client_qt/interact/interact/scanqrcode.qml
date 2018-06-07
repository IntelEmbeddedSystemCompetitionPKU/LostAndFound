import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import QZXing 2.3
import "."


Item{
    anchors.fill: parent

    property string dectag: "Nothing"
    Camera {
        id: camera

        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

        focus {
            focusMode: CameraFocus.FocusContinuous
            focusPointMode: CameraFocus.FocusPointAuto
        }
    }

    VideoOutput {
        id: videoOutput
        source: camera
        anchors.fill: parent
        focus: visible
        filters:[zxingFilter]
        Rectangle {
            id: capturezone
            color: "red"
            opacity: 0.2
            width: parent.width/2
            height: parent.height/2
            anchors.centerIn: parent
        }
    }

    Text {
        id: resultLab
        font.pointSize: 15
        text: dectag
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: anchors.bottom
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
            enabledDecoders: QZXing.DecoderFormat_EAN_13 | QZXing.DecoderFormat_CODE_39 | QZXing.DecoderFormat_QR_CODE

            onTagFound: {
                dectag = tag;
            }

            tryHarder: false
        }

    }
}
