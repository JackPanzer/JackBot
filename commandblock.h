#ifndef COMMANDBLOCK_H
#define COMMANDBLOCK_H

#include <QThread>
#include "connectionsocket.h"

class CommandBlock : public QThread
{
private:
    ConnectionSocket *sock;
public:
    CommandBlock(ConnectionSocket *sock);
    ~CommandBlock();
    void ImJackPanzer();

    static bool CONNECTING;
protected:
    void run();
};

#endif // COMMANDBLOCK_H
