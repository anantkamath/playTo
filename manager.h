/*
    Copyright 2014 Anant Kamath <kamathanant@gmail.com>
*/

#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

#include "renderer.h"
#include <dbus/ManagerIface.h>

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QString filepath, QObject *parent = 0);

    Q_PROPERTY(QList<QObject*> rendererModel READ getRenderers NOTIFY rendererModelUpdated)
    inline QList<QObject*> getRenderers() const
    { return renderers; }

signals:
    void rendererModelUpdated();
    void scanFinished();
public slots:
    void rendererClicked(Renderer*);
    void getRenderersFinished(QDBusPendingCallWatcher *call);
    void windowClosing();
    void playPause();
    void stop();
    void scan();
    void addRenderer(const QDBusObjectPath &);
    void removeRenderer(const QDBusObjectPath &);
private:
    ManagerIface *m;
    QString filepath;
    QList<QObject*> renderers;
    Renderer *activeRenderer;
};

#endif // MANAGER_H
