#include <QApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "Simulation.h"
#include "DataSource.h"

int main(int argc, char *argv[])
{
    qputenv("QSG_RHI_BACKEND", "opengl");
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QScopedPointer<Simulation> simulation(Simulation::getSimulation());
    engine.rootContext()->setContextProperty("Simulation", simulation.data());
    qmlRegisterType<DataSource>("DataSource", 1, 0, "DataSource");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
