/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -p PushHostIface -c PushHostIface introspection/com.intel.dLeynaRenderer.PushHost.xml -N
 *
 * qdbusxml2cpp is Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef PUSHHOSTIFACE_H_1419719887
#define PUSHHOSTIFACE_H_1419719887

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.intel.dLeynaRenderer.PushHost
 */
class PushHostIface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "com.intel.dLeynaRenderer.PushHost"; }

public:
    PushHostIface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~PushHostIface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QString> HostFile(const QString &Path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(Path);
        return asyncCallWithArgumentList(QLatin1String("HostFile"), argumentList);
    }

    inline QDBusPendingReply<> RemoveFile(const QString &Path)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(Path);
        return asyncCallWithArgumentList(QLatin1String("RemoveFile"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif