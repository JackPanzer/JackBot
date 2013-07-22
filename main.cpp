#include <QtGui/QApplication>
#include "commandwindow.h"
#include "connectionsocket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //CommandWindow w;
    //w.show();

    ConnectionSocket conn("JackBot", "miclavedered1", "ifg.ircnode.com", "#jackbot", 6667);
    conn.Conectar();

    return a.exec();
}
