/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -p PushHostIface -c PushHostIface introspection/com.intel.dLeynaRenderer.PushHost.xml -N
 *
 * qdbusxml2cpp is Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "PushHostIface.h"

/*
 * Implementation of interface class PushHostIface
 */

PushHostIface::PushHostIface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

PushHostIface::~PushHostIface()
{
}
