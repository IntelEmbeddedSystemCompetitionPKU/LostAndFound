import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.VirtualKeyboard 2.2
import QtQuick.Controls 1.2
import "."

ApplicationWindow {
    id: rootwindow
    visible: true
    width: Screen.width
    height: Screen.height

    Loader {
        id: appLoader
        anchors.fill: parent
        visible: true
        source: "manager.qml"
        asynchronous: false
    }
    InputPanel {
            id: inputPanel
            z: 99
            x: 0
            y: rootwindow.height
            width: rootwindow.width

            states: State {
                name: "visible"
                when: inputPanel.active
                PropertyChanges {
                    target: inputPanel
                    y: rootwindow.height - inputPanel.height
                }
            }
            transitions: Transition {
                from: ""
                to: "visible"
                reversible: true
                ParallelAnimation {
                    NumberAnimation {
                        properties: "y"
                        duration: 250
                        easing.type: Easing.InOutQuad
                    }
                }
            }
    }

}

