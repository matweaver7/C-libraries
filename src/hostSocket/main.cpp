#include "socketInterface/socketInterface.h"

#include <iostream>

void test(void * data) {

    std::cout << "We recieved: " << *(char*) data << std::endl;
}
int main(int argc, char *argv[]) {
    
    socketInterface socket1 = socketInterface();
    socket1.connect(44325);
    socket1.listenInterface(&test);
    socket1.closeInterface();
    return 0;
}