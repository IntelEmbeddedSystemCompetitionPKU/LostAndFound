import QtQuick 2.0
Item {
    id: manager
    anchors.fill: parent

    property var lastPages: []
    property int __currentIndex: 0
    property string intent: ""
    Component.onCompleted: {
       showPage("MainActivity.qml");
    }

    function prePage() {
        lastPages.pop();
        pageLoader.setSource(lastPages[lastPages.length-1]);
        __currentIndex = lastPages.length - 1;
    }

    function showPage(name) {
        lastPages.push(name);
        pageLoader.setSource(name);
        __currentIndex = lastPages.length - 1;
    }

    function popToPage(name) {
        while(lastPages[lastPages.length-1] != name && lastPages.length !== 1) {
            lastPages.pop();
        }
        pageLoader.setSource(lastPages[lastPages.length-1]);
        __currentIndex = lastPages.length-1;
    }
    function setIntent(name) {
        intent = name
    }
    function getIntent() {
        return intent
    }

    Loader {
        id: pageLoader
        anchors.fill: parent
        visible: true
        onStateChanged: {
            if(status == Loader.Ready) {
                pageLoader.item.forceActiveFocus();
            }
        }
    }
}
