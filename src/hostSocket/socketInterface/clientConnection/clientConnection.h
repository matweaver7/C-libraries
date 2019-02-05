#ifndef CLIENT_CONNECTION_H
#define CLIENT_CONNECTION_H

#include <unistd.h>
#include <string>
class clientConnection {
    private:
        int clientFD;
    public:
    // TO-DO: add messaging for failures
        clientConnection(int _clientFD);
        ~clientConnection();
        // not sure if it should be void. Will think on that more.
        char read();
        // same here. Void?
        void write(char message);
        void close();
};

#endif