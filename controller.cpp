#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{

}

int Controller::myVar() const
{
    return m_myVar;
}

void Controller::setMyVar(int myVar)
{
    if (m_myVar == myVar)
        return;

    m_myVar = myVar;
    emit myVarChanged(m_myVar);
}
