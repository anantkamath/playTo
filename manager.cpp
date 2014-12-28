/*
    Copyright 2014 Anant Kamath <kamathanant@gmail.com>
*/

#include "manager.h"

#include <unistd.h>

#include <QDebug>

#include <dbus/dbus.h>
#include <dbus/ManagerIface.h>
#include <dbus/RendererDeviceIface.h>
#include <dbus/PushHostIface.h>
#include <dbus/PlayerIface.h>



Manager::Manager(QString filepath, QObject *parent) :
    QObject(parent), filepath(filepath)
{
    m = new ManagerIface(RENDERER_SERVICE, ROOT_OBJECT_PATH, QDBusConnection::sessionBus());
    QDBusReply<QVariant> rescanReply = m->Rescan();
    qDebug()<<rescanReply.isValid();

    usleep(3*1000*1000);

    QDBusReply<QList<QDBusObjectPath> > getRendererReply = m->GetRenderers();
    foreach (const QDBusObjectPath &r, getRendererReply.value()) {
        qDebug()<<r.path();
        renderers.append(new RendererDeviceIface(RENDERER_SERVICE, r.path(), QDBusConnection::sessionBus()));
    }
}

void Manager::rendererClicked(RendererDeviceIface* renderer)
{
    qDebug()<<renderer->property("FriendlyName");
    activeRenderer = renderer;
    pushHostIface = new PushHostIface(RENDERER_SERVICE, activeRenderer->path(), QDBusConnection::sessionBus());
    QString hostedURI = pushHostIface->HostFile(filepath);
    playerIface = new PlayerIface(RENDERER_SERVICE, activeRenderer->path(), QDBusConnection::sessionBus());
    playerIface->OpenUri(hostedURI);
    playerIface->Play();
}

void Manager::windowClosing()
{
    if(activeRenderer)
        playerIface->Stop();
    m->Release();
}

void Manager::playPause()
{
    playerIface->PlayPause();
}

void Manager::stop()
{
    playerIface->Stop();
}
