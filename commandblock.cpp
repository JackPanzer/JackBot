#include "commandblock.h"

bool CommandBlock::CONNECTING = true;

CommandBlock::CommandBlock(ConnectionSocket *sock)
{
    this->sock = sock;
}

CommandBlock::~CommandBlock()
{}

void CommandBlock::ImJackPanzer()
{
    do{
        //Dormimos hasta que por fin tenemos conexión
        this->sleep(1000);
    }while(!CONNECTING);
    QString user, pass, channel;
    user = sock->getUser();
    pass = sock->getPass();
    channel = sock->getChannel();

    sock->sendCommand(QString("PASS "+ pass +"\n"));
    sock->sendCommand(QString("NICK "+ user +"\n"));
    sock->sendCommand(QString("USER "+ user +" tolmoon tolsun :Jack Panzer Bot\r\n"));
    sock->sendCommand(QString("JOIN "+channel+"\n"));
}

void CommandBlock::run()
{
}
