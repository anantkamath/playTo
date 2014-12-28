/*
    Copyright 2014 Anant Kamath <kamathanant@gmail.com>
*/

#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

#include <dbus/ManagerIface.h>
#include <dbus/RendererDeviceIface.h>
#include <dbus/PushHostIface.h>
#include <dbus/PlayerIface.h>

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QString filepath, QObject *parent = 0);

    Q_PROPERTY(QList<QObject*> rendererModel READ getRenderers)
    inline QList<QObject*> getRenderers() const
    { return renderers; }

    Q_PROPERTY(QObject* player READ getPlayer)
    inline QObject* getPlayer() const
    { return playerIface; }

signals:

public slots:
    void rendererClicked(RendererDeviceIface*);
    void windowClosing();
    void playPause();
    void stop();
private:
    ManagerIface *m;
    QString filepath;
    QList<QObject*> renderers;
    RendererDeviceIface *activeRenderer;
    PushHostIface *pushHostIface;
    PlayerIface *playerIface;
};

#endif // MANAGER_H
