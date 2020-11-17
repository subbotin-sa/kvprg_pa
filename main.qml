import QtQuick 2.15
import QtQuick.Window 2.15
import tstqml 1.0
import QtQuick.Controls 1.0

Window {

    width: 400
    height: 600
    visible: true

    TableView {
        anchors.fill: parent
        anchors.margins: 10
        clip: true

        model: TableModel {
            objectName: "table_model"
        }

        TableViewColumn {
            width: 100
            horizontalAlignment: Text.AlignHCenter
            title: "Id"
            role: "id"
        }
        TableViewColumn {
            width: 160
            horizontalAlignment: Text.AlignHCenter
            title: "Name"
            role: "name"
        }
        TableViewColumn {
            width: 100
            horizontalAlignment: Text.AlignHCenter
            title: "Phone"
            role: "phone"
        }

        itemDelegate: Item {
            Text {
                anchors.centerIn: parent
                renderType: Text.NativeRendering
                text: styleData.value
            }
        }
    }
}
