#include <iostream>

#include "scanner/Scanner.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Pass directory as parameter";
        return 1;
    } else {
        std::cout << "Listing for " << argv[1];
    }

	titanic::scanner::FileInfo fileInfo("Booyah");
	std::cout << fileInfo.getFilename() << std::endl;

    titanic::scanner::Scanner scanner;
    std::vector<titanic::scanner::FileInfo> foundFiles = scanner.findFiles(argv[1]);
    for (auto fileIt = foundFiles.begin(); fileIt < foundFiles.end(); ++fileIt) {
        std::cout << fileIt->getFilename() << std::endl;
    }

	return 0;
}
