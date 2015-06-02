#include "citymodel.h"

CityModel::CityModel(QObject *parent) : QAbstractTableModel(parent) {

}

int CityModel::rowCount(const QModelIndex & /*parent*/) const {
   return m_data_list.length();
}

int CityModel::columnCount(const QModelIndex & /*parent*/) const {
    return 3;
}

QVariant CityModel::data(const QModelIndex &index, int role) const {

    switch(role)
    {
        case RoleOne:
            return m_data_list.at(index.row())->getID();
        case RoleTwo:
            return m_data_list.at(index.row())->getX();
        case RoleThree:
            return m_data_list.at(index.row())->getY();
    }

    return QVariant();
}

bool CityModel::setData(const QModelIndex & index, const QVariant & value, int role) {

    qDebug() << "setData() called with:" << value;

    switch(role)
    {
        case RoleOne:
            m_data_list[index.row()]->setID(value.toInt());
        case RoleTwo:
            m_data_list[index.row()]->setX(value.toInt());
        case RoleThree:
            m_data_list[index.row()]->setY(value.toInt());
    }

    return true;
}

QHash<int, QByteArray> CityModel::roleNames() const {

    QHash<int, QByteArray> roles;
    roles[RoleOne] = "City";
    roles[RoleTwo] = "X";
    roles[RoleThree] = "Y";
    return roles;
}

void CityModel::addCity(int count, int x, int y) {
    City *m_simpledata;
    m_simpledata = new City(count, x, y);
    m_data_list.append(m_simpledata);
    layoutChanged();
}

void CityModel::print_rows() {

    qDebug() << "Model Data:";

    for (int i=0; i < m_data_list.length(); i++) {
        qDebug() << "At" << i << ":" << m_data_list.at(i)->getID() << m_data_list.at(i)->getX() << m_data_list.at(i)->getY();
    }

}
