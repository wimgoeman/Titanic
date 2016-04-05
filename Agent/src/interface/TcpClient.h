#pragma once

#include <string>
#include <Poco/Net/SocketAddress.h>

namespace titanic {
namespace interface {

class TcpClient {
public:
	TcpClient(const std::string& ip = "127.0.0.1", const unsigned short port = 2600);
	~TcpClient();

	void sendCommand(const std::string& command);

private:
	Poco::Net::SocketAddress _serverAddr;

};

}
}