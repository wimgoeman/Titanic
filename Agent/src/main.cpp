#include <iostream>

#include "interface/TcpClient.h"

int main(int argc, char* argv[]) {
	std::cout << "(. )( .)" << std::endl;
	std::string command = "exit";
	if (argc > 1) {
		command = argv[1];
	}
	titanic::interface::TcpClient tcpClient;
	std::cout << "Command: " << command << std::endl;
	tcpClient.sendCommand(command);

	std::cout << "Done!" << std::endl;
	return 0;
}
