#include "clientConnection.h"
#include <iostream>

clientConnection::clientConnection(int _clientFD) {
    clientFD = _clientFD;
}
clientConnection::~clientConnection() {
    close();
}
char clientConnection::read() {
    // this will eventually have to be real data sizing. Switch to using header to get size.
    char ch;
    if (::read(clientFD, &ch, sizeof(ch)) > 0) {
        return(ch);
    }
}
void clientConnection::write(char message) {
	if (::write(clientFD, &message, sizeof(message)) < 0) {
		close();
	}
}
void clientConnection::close() {
    if (clientFD > 0) {
        ::close(clientFD);
    }
}