/*
    Copyright 2014 Anant Kamath <kamathanant@gmail.com>
*/

import QtQuick 2.2
import QtQuick.Controls 1.1

Item {
    Text {
        id: activeRendererLabel
        anchors.horizontalCenter: parent.horizontalCenter
        text: window.activeRendererName
    }

    Slider {
        id: seekSlider
        width: 300
        anchors.top: activeRendererLabel.bottom
        anchors.topMargin: 20
        value: 0.5
    }

    Row {
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: seekSlider.bottom
        anchors.topMargin: 10
        Button {
            id: playPauseButton
            text: qsTr("Pause")
            onClicked: manager.playPause()
        }

        Button {
            id: stopButton
            text: qsTr("Stop")
            onClicked: manager.stop()
        }

        Slider {
            id: volumeSlider
            width: 100
            value: 0.5
        }
    }

    Timer {
            interval: 500;
            running: true;
            repeat: true
            //onTriggered: time.text = Date().toString()
    }
}
