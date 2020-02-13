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
    color: "#ff8c00"
    title: qsTr("Tic tac toe")
    property int inDeModel: 0
    property int fillX: 88
    property int fillO: 79
    property bool turn: false
    property string payer1turn: "First player turn X"
    property string payer2turn: "Second player turn O"
    ModelBoard{
        id: modelBoard
    }

    Connections{
        target: modelBoard
        onSendToQML:{
            textWhoWin.text=msg
            tv.enabled=false
            turnWho.text=""
        }
    }

    Text{
        id: textWhoWin
        x: 110
        y: 16
        anchors.bottom: boardPlace.top
        anchors.top: parent.top
        fontSizeMode: Text.Fit
        font.pixelSize: 44
        width: parent.width*0.6
        color: "#3b3334"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text{
        id: turnWho
        font.pixelSize: turnWho.height/2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        width: parent.width*0.6
        height: 50
        text: payer1turn
        fontSizeMode: Text.HorizontalFit
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.top: boardPlace.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        font.bold: true
        color: "#3b3334"
    }


    Rectangle{
        id: boardPlace
        anchors.centerIn: parent
        width: parent.width-20
        height: width
        border.color: "#3b3334"
        border.width: 2
        TableView{
            id: tv
            anchors.centerIn: parent
            width: parent.width-4
            height: width
            model: modelBoard
            delegate: Rectangle{
                id: empty
                implicitHeight: tv.width/3
                implicitWidth: tv.width/3
                border.color: "#3b3334"
                border.width: 2
                color: "#ff8c00"
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        if(turn==false)
                        {
                            model.field = fillX
                            turn=!turn
                            turnWho.text=payer2turn
                        }
                        else
                        {
                            model.field = fillO
                            turn=!turn
                            turnWho.text=payer1turn
                        }
                        modelBoard.check()
                    }
                }
                Text {
                    anchors.fill:parent
                    text: model.field
                    font.bold: false
                    font.family: "Verdana"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 133
                    color: "#3b3334"
                }
            }


        }
    }

    Rectangle {
        id: continueButton
        z:2
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.top: boardPlace.bottom
        anchors.bottom: parent.bottom
        anchors.left: turnWho.right
        anchors.right: parent.right
        height: turnWho.height

        color: "#ff8c00"
        Text {
            anchors.fill: parent
            //fontSizeMode: Text.Fit
            font.pixelSize: continueButton.height/2
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("Restart")
            fontSizeMode: Text.HorizontalFit
            font.bold: true
            color: "#3b3334"
        }
        MouseArea{
            anchors.fill: parent
        onClicked: {
            turnWho.text=payer1turn
            turn= false
            modelBoard.clean()
            tv.enabled=true
            textWhoWin.text=""

        }

        }


    }
}


