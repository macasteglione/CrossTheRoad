#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>

class Client {
private:
  int client_fd;
  struct sockaddr_in servaddr;

  void initClient();

public:
  Client();
  ~Client();
};

#endif // !SERVER_H
