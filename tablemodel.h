#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <qqml.h>
#include <QAbstractTableModel>
#include <QFile>


class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(0)

    struct record{
        QString id;
        QString name;
        QString phone;
    };

public:
    enum Role {
        id=Qt::UserRole,
        name,
        phone
    };

    int rowCount(const QModelIndex & = QModelIndex()) const override
    { return m_data.size(); }

    int columnCount(const QModelIndex & = QModelIndex()) const override
    { return 3; }

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    bool loadData(const QString& fileName);
    void setupData(const QVector<record>& data);

private:
    QVector<record> m_data;
};

#endif // TABLEMODEL_H
