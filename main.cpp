#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "tsp.h"
#include "citymodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Tsp receiver;
    CityModel model;
    engine.rootContext()->setContextProperty("theModel", &model);
    engine.rootContext()->setContextProperty("receiver", &receiver);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
