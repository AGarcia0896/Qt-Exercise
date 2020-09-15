#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>
#include <QTimer>

class Singleton : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int maxValue READ maxValue WRITE setMaxValue NOTIFY maxValueChanged)

public:
    explicit Singleton(QObject *parent = nullptr);

    int maxValue() const;
    void setMaxValue(int maxValue);

    Q_INVOKABLE void startProgress();
    //Q_INVOKABLE void startProgress(Q);
    Q_INVOKABLE void stopProgress();


    enum ProgressBarColor {
        RED,
        GREEN,
        BLUE,
        CYAN
    };

    Q_ENUM(ProgressBarColor)

signals:
    void maxValueChanged(int maxValue);
    void timerValueChanged();

private:
    int m_maxValue;
    QTimer * m_timer;
};

#endif // SINGLETON_H
