#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    const char *hostname = "example.com";
    const char *port = "80";
    struct addrinfo hints, *addrinfoResults;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &addrinfoResults) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    sockfd = socket(addrinfoResults->ai_family, addrinfoResults->ai_socktype, addrinfoResults->ai_protocol);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, addrinfoResults->ai_addr, addrinfoResults->ai_addrlen) < 0) {
        perror("connect");
        return 1;
    }

    char request[256];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return 1;
    }

    char response[4096];
    ssize_t bytesReceived;
    while ((bytesReceived = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytesReceived] = '\0';
        printf("%s", response);
    }

    if (bytesReceived < 0) {
        perror("recv");
        return 1;
    }

    close(sockfd);
    freeaddrinfo(addrinfoResults);
    return 0;
}
