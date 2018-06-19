import QtQuick 2.0
import user.DataManager 1.0
Item {
    id: manager
    anchors.fill: parent

    property var lastPages: []
    property int __currentIndex: 0

    Component.onCompleted: {
       showPage("MainActivity.qml");
    }
    DataManager {
        id: mydata
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


    function setUUID() {
        mydata.setUUID()
    }
    function getDir() {
        return mydata.getDir()
    }
    function processImage() {
        mydata.processImage()
    }
    function addDesc(desc) {
        mydata.addDescription(desc)
    }
    function isExist(name) {
        return mydata.isExist(name)
    }
    function popOut(name) {
        return mydata.popOut(name)
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
