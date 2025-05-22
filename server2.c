#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int s, ns;
    struct sockaddr_in sa, ca;
    socklen_t l = sizeof(ca);
    char b[2048];

    s = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8081);
    sa.sin_addr.s_addr = INADDR_ANY;

    bind(s, (struct sockaddr*)&sa, sizeof(sa));
    listen(s, 5);
    ns = accept(s, (struct sockaddr*)&ca, &l);
    recv(ns, b, sizeof(b), 0);
    for (int i = 0; b[i]; i++) {
        if (b[i] >= 'a' && b[i] <= 'z') b[i] -= 3;
        else if (b[i] >= 'A' && b[i] <= 'Z') b[i] -= 2;
        else if (b[i] >= '0' && b[i] <= '9') b[i] -= 1;
    }
    send(ns, b, strlen(b), 0);
    close(ns);
    close(s);
    return 0;
}