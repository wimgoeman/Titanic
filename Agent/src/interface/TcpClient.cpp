#include "TcpClient.h"

#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/StreamCopier.h"

namespace titanic {
namespace interface {

TcpClient::TcpClient(const std::string& ip, const unsigned short port) : _serverAddr(ip, port) {

}

TcpClient::~TcpClient() {

}

void
TcpClient::sendCommand(const std::string& command) {
	Poco::Net::StreamSocket socket(_serverAddr);
	Poco::Net::SocketStream stream(socket);
	stream << command;
	stream.flush();
}

}
}