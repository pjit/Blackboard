/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 1.0

TabWidget {
    id: tabs
    width: 640; height: 480

    Rectangle {
        property string title: "File"
        anchors.fill: parent
        color: "#e3e3e3"

        Rectangle {
            //anchors.fill: parent;
            anchors.margins: 20
            // color: "#ff7f7f"
            Text {
                width: parent.width - 20
                // anchors.centerIn: parent;
                // horizontalAlignment: Qt.AlignHCenter
                anchors.margins: 4
                text: "X: "
                // font.pixelSize: 20
                // wrapMode: Text.WordWrap
            }
        }
    }

    Rectangle {
        property string title: "View"
        anchors.fill: parent
        color: "#e3e3e3"

        Rectangle {
            anchors.fill: parent; anchors.margins: 20
            // color: "#7fff7f"
            Text {
                width: parent.width - 20
                anchors.centerIn: parent; horizontalAlignment: Qt.AlignHCenter
                text: "Flower stems are green"
                font.pixelSize: 20
                wrapMode: Text.WordWrap
            }
        }
    }

    Rectangle {
        property string title: "Format"
        anchors.fill: parent; color: "#e3e3e3"

		Rectangle {
            // anchors.fill: parent;
            anchors.margins: 2
            // color: "#7fff7f"
            Text {
                anchors.margins: 4
                width: 32
                // anchors.centerIn: parent;
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "X:"
                // font.pixelSize: 20
                // wrapMode: Text.WordWrap
            }
        }
		FocusScope {
			id: focusScope
			width: 64; height: 28
			anchors.margins: 4

			BorderImage {
				source: "images/lineedit-bg.png"
				width: parent.width; height: parent.height
				border { left: 4; top: 4; right: 4; bottom: 4 }
			}

			BorderImage {
				source: "images/lineedit-bg-focus.png"
				width: parent.width; height: parent.height
				border { left: 4; top: 4; right: 4; bottom: 4 }
				visible: parent.activeFocus ? true : false
			}

			Text {
				id: typeSomething
				anchors.fill: parent;
				anchors.leftMargin: 8
				verticalAlignment: Text.AlignVCenter
				text: "0"
				// color: "gray"
				// font.italic: true
			}

			MouseArea { 
				anchors.fill: parent
				onClicked: { focusScope.focus = true; textInput.openSoftwareInputPanel(); } 
			}

			TextInput {
				id: textInputSearch
				anchors { left: parent.left; leftMargin: 8; right: clear.left; rightMargin: 8; verticalCenter: parent.verticalCenter }
				focus: true
				selectByMouse: true
			}

			Image {
				id: clear
				anchors { right: parent.right; rightMargin: 8; verticalCenter: parent.verticalCenter }
				source: "images/clear.png"
				opacity: 0

				MouseArea { 
					anchors.fill: parent
					onClicked: { textInputSearch.text = ''; focusScope.focus = true; textInput.openSoftwareInputPanel(); }
				}
			}

			states: State {
				name: "hasText"; when: textInputSearch.text != ''
				PropertyChanges { target: typeSomething; opacity: 0 }
				PropertyChanges { target: clear; opacity: 1 }
			}

			transitions: [
				Transition {
					from: ""; to: "hasText"
					NumberAnimation { exclude: typeSomething; properties: "opacity" }
				},
				Transition {
					from: "hasText"; to: ""
					NumberAnimation { properties: "opacity" }
				}
			]
		}
	}
}
