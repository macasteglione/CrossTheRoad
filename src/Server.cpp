#include "Constants.h"
#include "Server.h"
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

Server::Server() { initServer(); }

Server::~Server() { close(server_fd); }

void Server::initServer() {
  if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    std::cerr << "Socket creation failed\n";
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  memset(&cliaddr, 0, sizeof(cliaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(SERVER_PORT);

  if (bind(server_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    std::cerr << "Bind failed\n";
    exit(EXIT_FAILURE);
  }

  std::cout << "Server initialized on port " << SERVER_PORT << "\n";

  char buffer[MAX_LINE];
  socklen_t addrlen = sizeof(cliaddr);
  int n = recvfrom(server_fd, buffer, MAX_LINE, 0, (struct sockaddr *)&cliaddr,
                   &addrlen);
  buffer[n] = '\0';
  std::cout << "Received message: " << buffer << "\n";

  const char *response = "Hello from server";
  sendto(server_fd, response, strlen(response), 0, (struct sockaddr *)&cliaddr,
         addrlen);
}
