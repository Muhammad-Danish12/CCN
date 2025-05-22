#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int s;
    struct sockaddr_in sa;
    char b[1024] = "Hello from Client";

    s = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8080);
    sa.sin_addr.s_addr = INADDR_ANY;

    connect(s, (struct sockaddr*)&sa, sizeof(sa));
    send(s, b, strlen(b), 0);
    close(s);
    return 0;
}