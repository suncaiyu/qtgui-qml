import QtQuick 2.1

Rectangle {
    id: root
    color: "green"
    width: 200
    height: 200

    // 发送给 Qt Widgets 的信号
    signal qmlSignal
    // 从 Qt Widgets 接收到的信号
    signal cSignal

    Text {
        id: myText
        text: "Click me"
        font.pointSize: 14
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: qmlSignal()
    }

    // 信号处理程序（处理从 Qt Widgets 接收到的信号）
    onCSignal: {
        root.color = "blue"
        myText.text = "Call the qml signal handler"
    }
}
