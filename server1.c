#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int s, ns;
    struct sockaddr_in sa, ca;
    socklen_t l = sizeof(ca);
    char b[1024];

    s = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8080);
    sa.sin_addr.s_addr = INADDR_ANY;

    bind(s, (struct sockaddr*)&sa, sizeof(sa));
    listen(s, 5);
    ns = accept(s, (struct sockaddr*)&ca, &l);
    recv(ns, b, sizeof(b), 0);
    printf("Received: %s\n", b);
    close(ns);
    close(s);
    return 0;
}