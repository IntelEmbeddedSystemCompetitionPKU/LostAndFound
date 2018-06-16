import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Controls.Styles 1.4
import QtMultimedia 5.8
import user.DataManager 1.0
import "."
Item{
    anchors.fill: parent
    property var savepath: null

    Button {
        id: cancelbutton
        width: 300
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
    Text {
        id: title
        text: "请输入额外描述信息"
        font.pixelSize: 35
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
        id: donebutton
        width: 200
        height: 200
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        onClicked: {
            var texts = textedit.getText(0,10000)
            manager.addDesc(texts)
            manager.processImage()
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
            text: "完成"
            font.pixelSize: 20
        }
    }

    Rectangle {
        width: parent.width - 30
        anchors.margins: 30
        anchors.top: title.bottom
        anchors.bottom: donebutton.top
        anchors.horizontalCenter: parent.horizontalCenter
        color: "gray"
        TextEdit {
            id: textedit
            font.pixelSize: 32
            anchors.fill: parent
        }
    }

}
