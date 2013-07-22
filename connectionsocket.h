#ifndef CONNECTIONSOCKET_H
#define CONNECTIONSOCKET_H

#include <QString>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMutex>
#include <QThread>

class ConnectionSocket : public QObject
{
    Q_OBJECT //La macro Q_OBJECT permite a una clase manejar signals y slots
private:
    bool exit;

    QString user;
    QString pass;
    QString domain;
    QString channel;
    QMutex *mutex;
    int port;

    QTcpSocket socket;

    void sendCommand(QString com);

public:
    ConnectionSocket(QString user, QString pass, QString domain, QString channel, int port);
    ~ConnectionSocket();

    inline QString getUser() { return this->user;}
    inline QString getPass() { return this->pass;}
    inline QString getDomain() { return this->domain;}
    inline QString getChannel() { return this->channel;}
    inline int getPort() { return this->port;}

    inline void setUser(QString target) { user = target;}
    inline void setPass(QString target) { pass = target;}
    inline void setDomain(QString target) { domain = target;}
    inline void setChannel(QString target) { channel = target;}
    inline void setPort(int target) { port = target;}

    void Conectar();

public slots:
    void Ejecucion();
    void CerrarSocket();
};

#endif // CONNECTIONSOCKET_H
