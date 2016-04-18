#include "TcpServer.h"

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/StreamCopier.h>
#include <iostream>

namespace titanic {
namespace interface {

TcpServer::TcpServer(const unsigned short port) : _port(port) {

}

TcpServer::~TcpServer() {

}

const unsigned short
TcpServer::getPort() const {
	return _port;
}

void
TcpServer::setPort(const unsigned short port) {
	_port = port;
}

std::string
TcpServer::receiveCommand() {
	std::string command;
	char buffer[1024];
	Poco::Net::ServerSocket tcpSocket(_port);
	std::cout << "Waiting for connection..." << std::endl;
	Poco::Net::StreamSocket openSocket = tcpSocket.acceptConnection();
	int bytesReceived = openSocket.receiveBytes(buffer, 1024);
	while (bytesReceived > 0) {
		command += std::string(buffer, bytesReceived);
		bytesReceived = openSocket.receiveBytes(buffer, 1024);
	}
	return command;
}

}
}