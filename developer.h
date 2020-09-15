#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <QObject>
#include "person.h"

class Developer : public Person
{
    Q_OBJECT
    Q_PROPERTY(QString role READ role WRITE setRole NOTIFY roleChanged)
    Q_PROPERTY(QString building READ building WRITE setBuilding NOTIFY buildingChanged)

public:
    explicit Developer(QObject *parent = nullptr);

    QString role() const;
    QString building() const;

    void setRole(QString role);
    void setBuilding(QString building);

signals:
    void roleChanged(QString role);
    void buildingChanged(QString building);

private:
    QString m_role;
    QString m_building;

};

#endif // DEVELOPER_H
