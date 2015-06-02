#ifndef CITYMODEL
#define CITYMODEL

#include <QAbstractTableModel>
#include <QDebug>
#include "tsp.h"

class CityModel : public QAbstractTableModel {
    Q_OBJECT
    public:
        explicit CityModel(QObject *parent = 0);
        enum MyRoles {
            RoleOne = Qt::UserRole + 1,
            RoleTwo,
            RoleThree
        };

    public:
        int rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        bool setData(const QModelIndex & index, const QVariant &value, int role = Qt::EditRole);
        QHash<int, QByteArray> roleNames() const;
        QList<City*> m_data_list;


    signals:

    public slots:
        void print_rows();
        void addCity(int count, int x, int y);
};

#endif // CITYMODEL

