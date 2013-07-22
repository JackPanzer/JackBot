#include "connectionsocket.h"
#include <iostream>

using namespace std;

ConnectionSocket::ConnectionSocket(QString user, QString pass, QString domain, QString channel, int port)
{
    exit = false;

    setUser(user);
    setPass(pass);
    setDomain(domain);
    setChannel(channel);
    setPort(port);

    mutex = new QMutex();

    QObject::connect(&socket, SIGNAL(connected()), this, SLOT(Ejecucion()));
    //QObject::connect(&socket, SIGNAL(disconnected()),this,SLOT(CerrarSocket()));
}

ConnectionSocket::~ConnectionSocket()
{

}

void ConnectionSocket::Conectar()
{
    //Comienza la secuencia de ejecución

    socket.connectToHost(domain, port);
}

void ConnectionSocket::Ejecucion()
{
    char *res = new char[8192];
    cout<<"Comenzando rutina de ejecucion"<<endl;
    if(socket.state() != QAbstractSocket::ConnectedState)
    {
        //Ha habido un problema a la hora de abrir el socket
        cout<<socket.errorString().toStdString()<<endl;
        return;
    }

    QString command;
    QString read;
    int readState;
    /*
    read = socket.readLine();
    cout<<read.toStdString()<<endl;

    read = socket.readLine();
    cout<<read.toStdString()<<endl;
    */

    //Socket abierto! vamos a enviarle información para comunicar que estamos vivos
    socket.waitForReadyRead();
    socket.readLine(res, 8192);
    cout<<res;

    socket.waitForReadyRead();
    socket.readLine(res, 8192);
    cout<<res;
    /*
    sendCommand(QString("Hola ircnode!"));

    command = "PASS "+ pass +"\n";
    sendCommand(command);

    command = "NICK "+ user +"\n";
    sendCommand(command);

    command = "USER "+ user +" tolmoon tolsun :Jack Panzer\r\n";
    sendCommand(command);

    command = "JOIN "+channel+"\n";
    sendCommand(command);
    */
    cout<<"Entrando en bucle principal de lectura del socket"<<endl;
    do{
        cout<<"Esperando a que haya info para leer"<<endl;
        socket.waitForReadyRead();

        socket.readLine(res, 8192);
        cout<<"Respuesta del servidor: "<<res;
    }while(socket.isOpen());
/*

    socket.waitForReadyRead();
    socket.readLine(res, 8192);
    cout<<res;

    socket.waitForReadyRead();
    socket.readLine(res, 8192);
    cout<<res;

    command = "PASS "+ pass +"\n";
    sendCommand(command);

    command = "NICK "+ user +"\n";
    sendCommand(command);

    command = "USER "+ user +" tolmoon tolsun :Jack Panzer\r\n";
    sendCommand(command);

    command = "JOIN "+channel+"\n";
    sendCommand(command);

    QString data;
*/
}

void ConnectionSocket::CerrarSocket()
{

}

void ConnectionSocket::sendCommand(QString com)
{
    mutex->lock();

    socket.write(com.toAscii().data());
    socket.flush();

    mutex->unlock();
}
