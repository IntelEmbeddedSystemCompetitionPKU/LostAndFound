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
        Text {
            text: "Cancel"
        }
    }
    Button {
        id: donebutton
        width: 300
        height: 200
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        onClicked: {
            var texts = textedit.getText(0,10000)
            manager.addDesc(texts)
            //print(texts)
            manager.processImage()
            manager.popToPage("MainActivity.qml")
        }
        Text {
            text: "Finished"
        }
    }

    Rectangle {
        width: parent.width - 30
        anchors.margins: 30
        anchors.top: parent.top
        anchors.bottom: donebutton.top
        anchors.horizontalCenter: parent.horizontalCenter
        color: "gray"
        TextEdit {
            id: textedit
            anchors.fill: parent
        }
    }

}
