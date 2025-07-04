#ifndef SERVER_HEADER
#define SERVER_HEADER

#include <netinet/in.h>

class Server {
private:
  int server_fd;
  struct sockaddr_in servaddr, cliaddr;

  void initServer();

public:
  Server();
  ~Server();
};

#endif // SERVER_HEADER
