#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
    int port, sockFD, sucessRate;
    struct sockaddr_in6 defaultConfig = {
        AF_INET6,
        htons(44325),
        0,
        in6addr_any,
        0     
    };
    bool keepFiring = true;
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
    
    while (keepFiring) {
        
    }

    close(sockFD);

    return 0;
}