#include <QDebug>
#include "singleton.h"

Singleton::Singleton(QObject *parent) : QObject(parent),
    m_maxValue(0),
    m_timer(new QTimer(this))
{
    m_timer->setInterval(1000);
    connect(m_timer,&QTimer::timeout,[=](){
        emit timerValueChanged();
    });
}

int Singleton::maxValue() const
{
    return m_maxValue;
}

void Singleton::setMaxValue(int maxValue)
{
    if (m_maxValue == maxValue)
        return;

    m_maxValue = maxValue;
    emit maxValueChanged(m_maxValue);
}

void Singleton::startProgress()
{
    qDebug() << "Start Progress Called from C++";
    m_timer->start();
}

void Singleton::stopProgress()
{
    m_timer->stop();
}
