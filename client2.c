#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int s;
    struct sockaddr_in sa;
    char b[2048], r[2048];

    FILE *f = fopen("fileData.txt", "r");
    fread(b, 1, sizeof(b), f);
    fclose(f);

    for (int i = 0; b[i]; i++) {
        if (b[i] >= 'a' && b[i] <= 'z') b[i] += 3;
        else if (b[i] >= 'A' && b[i] <= 'Z') b[i] += 2;
        else if (b[i] >= '0' && b[i] <= '9') b[i] += 1;
    }

    s = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8081);
    sa.sin_addr.s_addr = INADDR_ANY;

    connect(s, (struct sockaddr*)&sa, sizeof(sa));
    send(s, b, strlen(b), 0);
    recv(s, r, sizeof(r), 0);
    printf("Decrypted: %s\n", r);
    close(s);
    return 0;
}