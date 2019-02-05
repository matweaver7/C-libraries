#include "socketInterface.h"
#include "clientConnection/clientConnection.h"

//TO-DO: prune unnecessary libraries
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
socketInterface::socketInterface(){
    socketReader = -1;
    shouldListen = false;
};
socketInterface::~socketInterface() {
    closeInterface();
};
bool socketInterface::connect(int port) {

    struct sockaddr_in6 serverInfo; 

    // zeroing out server and setting configuration
    std::memset(&serverInfo, 0, sizeof(serverInfo));

    serverInfo.sin6_addr = in6addr_any;
    serverInfo.sin6_port = htons(port);
    serverInfo.sin6_family = AF_INET6;
    

    // creating server socket
    socketReader = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
    if (socketReader < 0) {
        socketReader = -1;
        return -1;
    }
    // binding server socket
    if(bind(socketReader, (struct sockaddr*) &serverInfo, sizeof(serverInfo)) < 0) {
        socketReader = -1;
        return -1;
    };
    return true;
}
// TO-DO: make this a threading pool
void socketInterface::listenInterface(void (*dataHandler)(void *)) {
    shouldListen = true;
    int clientSock = -1;
    struct sockaddr_in6 clientInfo; 
    socklen_t clientSize = sizeof(clientInfo);
    // zeroing out server and setting configuration
    std::memset(&clientInfo, 0, sizeof(clientInfo));

    listen(socketReader, 50);
    while (shouldListen) {
        // recieve client
        clientSock = accept(socketReader, (struct sockaddr *) &clientInfo, &clientSize);
        // test for errors
        if (clientSock < 0) {
            closeInterface();
        } 

        clientConnection* client = new clientConnection(clientSock);
        char ch = client->read();
        // THIS IS BAD!!! DON'T DO THIS. MEMORY MNGMT 101! FIX THIS!!!!
        dataHandler(&ch);

        client->write('s');

    }
};
void socketInterface::closeInterface() {
    shouldListen = false;    
    if (socketReader > 0) {
        close(socketReader);
    }
    socketReader = -1;
}
void socketInterface::write(){};

