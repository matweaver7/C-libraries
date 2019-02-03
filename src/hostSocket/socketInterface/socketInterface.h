#ifndef SOCKET_INTERFACE_H
#define SOCKET_INTERFACE_H

class socketInterface {
    private:
        int socketReader;
        bool shouldListen;
    public:
        socketInterface();
        ~socketInterface();
        bool connect(int port);
        void listenInterface(void (*dataHandler)(void*));
        void write();
        void closeInterface();
        
};
#endif