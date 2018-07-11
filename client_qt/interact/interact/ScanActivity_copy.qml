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







}
