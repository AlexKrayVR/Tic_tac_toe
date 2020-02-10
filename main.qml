import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Shapes 1.12

import ModelBoard 1.0
Window {
    id: window
    visible: true
    width: 440
    height: 580
    title: qsTr("Tic tac toe")
    property int inDeModel: 0
    property int fillX: 88
    property int fillO: 79
    property bool turn: false
    ModelBoard{
        id: modelBoard
    }

    Connections{
        target: modelBoard
        onSendToQML:{
            textWhoWin.text=msg
        }
    }

    Text{
        id: textWhoWin
        anchors.left: parent.left
        anchors.leftMargin: 0
        fontSizeMode: Text.Fit
        font.pixelSize: 44
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        width: parent.width/2
        height: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
    }

    Text{
        id: turnWho

        anchors.right: parent.right
        anchors.rightMargin: 0
        fontSizeMode: Text.Fit
        font.pixelSize: 44
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        width: parent.width/2
        height: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
    }


    Rectangle{
        anchors.centerIn: parent
        width: parent.width-20
        height: width
        border.color: "black"
        border.width: 1
        TableView{
            id: tv
            anchors.centerIn: parent
            width: parent.width-2
            height: width
            model: modelBoard
            delegate: Rectangle{
                id: empty
                implicitHeight: tv.width/3
                implicitWidth: tv.width/3
                border.color: "black"
                border.width: 1
                color: "grey"
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        if(turn==false)
                        {
                            model.field = fillX
                            turn=!turn
                        }
                        else
                        {
                            model.field = fillO
                            turn=!turn
                        }
                        modelBoard.check()
                    }
                }
                Text {
                    anchors.fill:parent
                    text: model.field
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 133
                }
            }
        }
    }


    Text{
        x: 170
        y: 15
        width: 100
        height: 50
        text:inDeModel
    }




}

/*##^##
Designer {
    D{i:2;anchors_height:50}
}
##^##*/
