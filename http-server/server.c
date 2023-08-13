#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE];

    // Read client's request
    read(client_fd, buffer, sizeof(buffer) - 1);

    printf("Here's the HTTP request:\n%s\n", buffer);

    // A basic HTTP response
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>\r\n";

    // Send the response
    write(client_fd, response, sizeof(response) - 1);

    // Close the connection
    close(client_fd);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        int client_fd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (client_fd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        handle_client(client_fd);
    }

    close(sockfd);
    return 0;
}
