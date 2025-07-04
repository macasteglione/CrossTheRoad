#include "Client.h"
#include "Server.h"
#include <gtest/gtest.h>
#include <thread>

void RunServer() { Server server; }

TEST(NetworkTest, ServerClientCommunication) {
  std::thread serverThread(RunServer);
  std::this_thread::sleep_for(std::chrono::seconds(1));

  testing::internal::CaptureStdout();
  Client client;
  std::string output = testing::internal::GetCapturedStdout();

  serverThread.join();

  EXPECT_NE(output.find("Hello from server"), std::string::npos)
      << "Client did not receive expected message from server.";
}
