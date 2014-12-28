/*
    Copyright 2014 Anant Kamath <kamathanant@gmail.com>
*/

import QtQuick 2.2
import QtQuick.Controls 1.1

Item {
    Text {
        id: label1
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Select device to stream to:")
    }

    ListView {
        id: rendererListView
        width: 200
        height: 200
        anchors.top: label1.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        model: manager.rendererModel
        delegate: Item {
            width: 200
            height: 48
            Button {
                anchors.horizontalCenter: window.horizontalCenter
                height:32
                width:200
                iconSource: model.modelData.IconURL
                text: model.modelData.FriendlyName
                onClicked: {
                    window.activeRendererName = model.modelData.FriendlyName;
                    manager.rendererClicked(model.modelData);
                    player.source = "player.qml";
                    rendererView.source = "";
                }
            }
        }
    }
}
