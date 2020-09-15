#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int myVar READ myVar WRITE setMyVar NOTIFY myVarChanged)

public:
    explicit Controller(QObject *parent = nullptr);
    int myVar() const;
    void setMyVar(int myVar);

signals:
    void myVarChanged(int myVar);

private:
    int m_myVar;

};

#endif // CONTROLLER_H
