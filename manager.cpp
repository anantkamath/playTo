/*
    Copyright 2014 Anant Kamath <kamathanant@gmail.com>
*/

#include "manager.h"

#include <QTimer>
#include <QDebug>

#include <unistd.h>
#include "dbus/dbus.h"
#include "dbus/ManagerIface.h"
#include "renderer.h"



Manager::Manager(QString filepath, QObject *parent) :
    QObject(parent), filepath(filepath)
{
    m = new ManagerIface(RENDERER_SERVICE, ROOT_OBJECT_PATH, QDBusConnection::sessionBus());
    QDBusPendingCall getRenderersCall = m->GetRenderers();
    QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(getRenderersCall, this);

    QObject::connect(watcher, SIGNAL(finished(QDBusPendingCallWatcher*)),
                     this, SLOT(getRenderersFinished(QDBusPendingCallWatcher*)));
}

void Manager::scan()
{
    m->Rescan();
    // renderersUpdated();QTimer::singleShot(3000, this, SIGNAL(scanFinished()));
}

void Manager::getRenderersFinished(QDBusPendingCallWatcher *call)
{
    qDebug()<<"hi";
    QDBusPendingReply<QList<QDBusObjectPath> > getRendererReply = *call;
    qDebug()<<getRendererReply.error();
    foreach (const QDBusObjectPath &r, getRendererReply.value()) {
        qDebug()<<r.path();
        renderers.append(new Renderer(r.path(), this));
    }
    emit rendererModelUpdated();
    connect(m, &ManagerIface::FoundRenderer, this, &Manager::addRenderer);
    //scan();
}

void Manager::rendererClicked(Renderer* renderer)
{
    //qDebug()<<renderer->property("FriendlyName");
    activeRenderer = renderer;
    activeRenderer->play(filepath);
}

void Manager::windowClosing()
{
    if(activeRenderer) {
        //activeRenderer->stop();
    }
    m->Release();
}

void Manager::playPause()
{
    activeRenderer->playPause();
}

void Manager::stop()
{
    activeRenderer->stop();
}

void Manager::addRenderer(const QDBusObjectPath & path)
{
    qDebug()<<path.path();
    renderers.append(new Renderer(path.path(), this));
    emit rendererModelUpdated();
}

void Manager::removeRenderer(const QDBusObjectPath & path)
{
    emit rendererModelUpdated();
}
