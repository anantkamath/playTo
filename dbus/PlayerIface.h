/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -p PlayerIface -c PlayerIface introspection/org.mpris.MediaPlayer2.Player.xml -N
 *
 * qdbusxml2cpp is Copyright (C) 2015 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef PLAYERIFACE_H
#define PLAYERIFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.mpris.MediaPlayer2.Player
 */
class PlayerIface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.mpris.MediaPlayer2.Player"; }

public:
    PlayerIface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~PlayerIface();

    Q_PROPERTY(double MaximumRate READ maximumRate)
    inline double maximumRate() const
    { return qvariant_cast< double >(property("MaximumRate")); }

    Q_PROPERTY(double MinimumRate READ minimumRate)
    inline double minimumRate() const
    { return qvariant_cast< double >(property("MinimumRate")); }

    Q_PROPERTY(QString PlaybackStatus READ playbackStatus)
    inline QString playbackStatus() const
    { return qvariant_cast< QString >(property("PlaybackStatus")); }

    Q_PROPERTY(double Rate READ rate WRITE setRate)
    inline double rate() const
    { return qvariant_cast< double >(property("Rate")); }
    inline void setRate(double value)
    { setProperty("Rate", QVariant::fromValue(value)); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> ByteSeek(qlonglong offset)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(offset);
        return asyncCallWithArgumentList(QStringLiteral("ByteSeek"), argumentList);
    }

    inline QDBusPendingReply<> GotoTrack(uint TrackNumber)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(TrackNumber);
        return asyncCallWithArgumentList(QStringLiteral("GotoTrack"), argumentList);
    }

    inline QDBusPendingReply<> Next()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Next"), argumentList);
    }

    inline QDBusPendingReply<> OpenNextUri(const QString &Uri, const QString &Metadata)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(Uri) << QVariant::fromValue(Metadata);
        return asyncCallWithArgumentList(QStringLiteral("OpenNextUri"), argumentList);
    }

    inline QDBusPendingReply<> OpenUri(const QString &Uri)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(Uri);
        return asyncCallWithArgumentList(QStringLiteral("OpenUri"), argumentList);
    }

    inline QDBusPendingReply<> OpenUriEx(const QString &Uri, const QString &Metadata)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(Uri) << QVariant::fromValue(Metadata);
        return asyncCallWithArgumentList(QStringLiteral("OpenUriEx"), argumentList);
    }

    inline QDBusPendingReply<> Pause()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Pause"), argumentList);
    }

    inline QDBusPendingReply<> Play()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Play"), argumentList);
    }

    inline QDBusPendingReply<> PlayPause()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("PlayPause"), argumentList);
    }

    inline QDBusPendingReply<> Previous()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Previous"), argumentList);
    }

    inline QDBusPendingReply<> Seek(qlonglong offset)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(offset);
        return asyncCallWithArgumentList(QStringLiteral("Seek"), argumentList);
    }

    inline QDBusPendingReply<> SetBytePosition(const QDBusObjectPath &trackid, qlonglong byte_position)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(trackid) << QVariant::fromValue(byte_position);
        return asyncCallWithArgumentList(QStringLiteral("SetBytePosition"), argumentList);
    }

    inline QDBusPendingReply<> SetPosition(const QDBusObjectPath &trackid, qlonglong position)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(trackid) << QVariant::fromValue(position);
        return asyncCallWithArgumentList(QStringLiteral("SetPosition"), argumentList);
    }

    inline QDBusPendingReply<> SetUri(const QString &Uri, const QString &Metadata)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(Uri) << QVariant::fromValue(Metadata);
        return asyncCallWithArgumentList(QStringLiteral("SetUri"), argumentList);
    }

    inline QDBusPendingReply<> Stop()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Stop"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif
