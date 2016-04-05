#pragma once

#include <string>

namespace titanic {
namespace interface {

class TcpServer {
public:
	TcpServer(unsigned short port = 2600);
	~TcpServer();

	const unsigned short getPort() const;
	void setPort(const unsigned short port);

	std::string receiveCommand();

private:
	unsigned short _port;
};

}
}