/*
    Copyright 2014 Anant Kamath <kamathanant@gmail.com>
*/

import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: window
    visible: true
    width: 320
    height: 300
    minimumWidth: 320
    minimumHeight: 300
    title: qsTr("PlayTo")
    property string activeRendererName: ""

    onClosing: manager.windowClosing()


    Loader {
        id: rendererView
        width: 300
        height: 200
        anchors.centerIn: parent
        source: "rendererView.qml"
    }

    Loader {
        id: player
        width: 300
        height: 200
        anchors.centerIn: parent
        source: ""
    }
}
