/*
    Copyright 2014 Anant Kamath <kamathanant@gmail.com>
*/

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCommandLineParser>
#include <QDBusReply>
#include <QFileDialog>
#include <QDebug>

#include "manager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("playTo");
    QCoreApplication::setApplicationVersion("0.1");

    QCommandLineParser parser;
    parser.setApplicationDescription("A simple DLNA control point");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("filename", QCoreApplication::translate("main", "File to play (stream) on a DLNA renderer."));
    parser.process(app);

    QString filename;
    const QStringList args = parser.positionalArguments();

    if (args.isEmpty()) {
        QString path = QFileDialog::getOpenFileName();
        if (path.isNull()) {
            fputs(qPrintable("No file selected. Exiting."), stderr);
            return 1;
        }
        else {
            filename = path;
        }
        //fputs(qPrintable(parser.helpText()), stderr);
        //return 1;
    }

    else {
        filename = args.at(0);
    }
    //filename = "aa";

    Manager *manager = new Manager(filename);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("manager", QVariant::fromValue(manager));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
