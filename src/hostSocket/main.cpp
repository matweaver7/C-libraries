#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;
struct sockadd_in6 {
    sa_family_t     sin6_family;   /* AF_INET6 */
    in_port_t       sin6_port;     /* port number */
    uint32_t        sin6_flowinfo; /* IPv6 flow information */
    struct in6_addr sin6_addr;     /* IPv6 address */
    uint32_t        sin6_scope_id; /* Scope ID (new in 2.4) */
};
int main(int argc, char *argv[]) {
    int port, sockFD;

    sockFD = socket(AF_INET6, SOCK_STREAM, 0);
    if (sockFD < 0) {
        cout << "failed" << endl;
    }
    cout << "sucess" << endl;
    return 0;
}