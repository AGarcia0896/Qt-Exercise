#include "developer.h"

Developer::Developer(QObject *parent) : Person(parent)
{

}

QString Developer::role() const
{
    return m_role;
}

QString Developer::building() const
{
    return m_building;
}

void Developer::setRole(QString role)
{
    if (m_role == role)
        return;

    m_role = role;
    emit roleChanged(m_role);
}

void Developer::setBuilding(QString building)
{
    if (m_building == building)
        return;

    m_building = building;
    emit buildingChanged(m_building);
}
