#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>


#define PORT 8080


int main(int argc, char **argv)
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    char *hello = "HTTP/1.1 200 OK\r\n\r\nHello from server";


    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) <= 0)
    {
        perror("Sockett failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failedd" );
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0 )
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        printf("connection approved on port 8080\n");
        char buffer[1024] = {0};
        int vl  = read(new_socket, buffer, 1024);
        if (vl == 0)
            break;
        printf("zbi : %s\n",buffer);
        send(new_socket, "zebiiii" , 8,0);
    }

printf("done");

    return 0;
}

