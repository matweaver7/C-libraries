#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
    int port, sockFD, sucessRate, clientSock, readSuccess, writeSuccess, numb;
    bool keepFiring = true;
    socklen_t clientSize;
    srand (time(NULL));
    
	char ch;

    struct sockaddr_in6 defaultConfig = {
        AF_INET6,
        htons(44325),
        0,
        in6addr_any,
        0     
    };
    struct sockaddr_in6 clientConfig;
    
    sockFD = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
    if (sockFD < 0) {
        cout << "failed" << endl;
    }
    cout << "sucess" << endl;

    sucessRate = bind(sockFD, (struct sockaddr*) &defaultConfig, sizeof(defaultConfig));
    
    if (sucessRate < 0) {
        cout << "failed bind" << endl;
    }
    cout << "sucess bind" << endl;

    listen(sockFD, 50);
    clientSize= sizeof(clientConfig);
    while (keepFiring) {
        clientSock = accept(sockFD, (struct sockaddr *) &clientConfig, &clientSize);
        if (clientSock < 0) {
            keepFiring = false;
            cout << "this was a failure" << endl;
        } else {
            cout << "freak. That worked?" << endl;
        }
        readSuccess = read(clientSock, &ch, sizeof(ch));
        if (readSuccess < 0) {
            cout << "that failed" << endl;
        } else {
            cout << "We recieved: " << ch << endl;
        }
        numb = 126 - rand() % 93;
        ch = (char) numb; 
        writeSuccess = write(clientSock, &ch, sizeof(ch));
        if(writeSuccess < 0) {
          cout << "that failed" << endl;
        } else {
            cout << "Sending: " << ch << endl;
        }

        close(clientSock);
        cout << "Connection closed" << endl;

    }

    close(sockFD);

    return 0;
}