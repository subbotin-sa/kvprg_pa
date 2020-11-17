#include "tablemodel.h"

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case id:
        return m_data.at(index.row()).id;
    case name:
        return m_data.at(index.row()).name;
    case phone:
        return m_data.at(index.row()).phone;
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[id] = "id";
    roles[name] = "name";
    roles[phone] = "phone";
    return roles;
}

bool TableModel::loadData(const QString& fileName)
{
    QVector<record> data;

    QFile file(fileName);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
//        qDebug() << "File not exists";
        setupData(data);
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QVector<QString> temp;
        for (QString item : line.split(";"))
            temp.push_back(item);
        // простая валидация - записываем строчку только если три поля или три поля с ";" на конце
        if(temp.size() == 3 || (temp.size()==4 && temp.at(3).isEmpty()))
        {
            record rec;
            rec.id = temp.at(0);
            rec.name = temp.at(1);
            rec.phone = temp.at(2);
            data.push_back(rec);
        }
    }
    setupData(data);

    file.close();
    return true;
}

void TableModel::setupData(const QVector<record>& data)
{
    // cleanup
    beginRemoveRows(QModelIndex(), 0, m_data.size()-1);
    m_data.clear();
    endRemoveRows();

    //setup
    beginInsertRows(QModelIndex(), 0, data.size()-1);
    m_data = data;
    endInsertRows();
}
