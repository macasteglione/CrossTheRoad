#include "Client.h"
#include "Constants.h"
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

Client::Client() { initClient(); }

Client::~Client() { close(client_fd); }

void Client::initClient() {
  if ((client_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    std::cerr << "Socket creation failed\n";
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(SERVER_PORT);

  const char *msg = "Hola servidor!";
  sendto(client_fd, msg, strlen(msg), 0, (const struct sockaddr *)&servaddr,
         sizeof(servaddr));

  char buffer[MAX_LINE];
  socklen_t len = sizeof(servaddr);
  int n = recvfrom(client_fd, buffer, MAX_LINE, 0, (struct sockaddr *)&servaddr,
                   &len);
  buffer[n] = '\0';
  std::cout << buffer << "\n";
}
