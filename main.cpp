#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "controller.h"
#include "person.h"
#include "developer.h"
#include "singleton.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Controller controller;
    Singleton singleton;
    //Person::objectCount = 0;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("Controller", &controller);
    engine.rootContext()->setContextProperty("Singleton", &singleton);

    const QUrl url_1(QStringLiteral("qrc:/main.qml"));
    const QUrl url_2(QStringLiteral("qrc:/second.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url_1, url_2](QObject *obj, const QUrl &objUrl) {
        if (!obj && (url_1 == objUrl || url_2 == objUrl))
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url_1);
    engine.load(url_2);

    return app.exec();
}
