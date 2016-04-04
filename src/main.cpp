#include <iostream>

#include <algorithm>

#include <Poco/Stopwatch.h>
#include "scanner/Scanner.h"
#include "parser/Parser.h"


int main(int argc, char* argv[]) {
	// Read input
	std::string listPath;
    if (argc < 2) {
        std::cout << "No path specified, listing current dir";
		listPath = ".";
    } else {
        std::cout << "Listing for " << argv[1] << std::endl;
		listPath = argv[1];
    }

	// Find files
    titanic::scanner::Scanner scanner;
	Poco::Stopwatch stopWatch;
	stopWatch.start();
    std::vector<titanic::artefact::File> foundFiles = scanner.findFiles(listPath);
	unsigned long scannerTime = (unsigned long) stopWatch.elapsed();

	// Parse files
	unsigned long totalSize = 0;
    for (auto fileIt = foundFiles.begin(); fileIt < foundFiles.end(); ++fileIt) {
		titanic::parser::Parser parser(fileIt->getPath());
		parser.parse();
		fileIt->setHash(parser.getHash());
		fileIt->setSize(parser.getSize());
		totalSize += parser.getSize();
    }
	unsigned long parserTime = ((unsigned long) stopWatch.elapsed()) - scannerTime;

	// Smallest files
	const unsigned int displayCount = 20;
	std::cout << "========================================================= " << displayCount << " smallest files:" << std::endl;
	unsigned int displayCounter = 0;
	std::sort(foundFiles.begin(), foundFiles.end(), [](titanic::artefact::File a, titanic::artefact::File b) { return a.getSize() < b.getSize(); });
	for (auto fileIt = foundFiles.begin(); fileIt < foundFiles.end() && displayCounter < displayCount; ++fileIt) {
		std::cout << fileIt->getPath() << " (" << (fileIt->getSize() / 1024) << " kb): " << fileIt->getHash() << std::endl;
		++displayCounter;
	}

	// Largest files
	std::cout << "========================================================= " << displayCount << " largest files:" << std::endl;
	displayCounter = 0;
	for (auto fileIt = foundFiles.rbegin(); fileIt < foundFiles.rend() && displayCounter < displayCount; ++fileIt) {
		std::cout << fileIt->getPath() << " (" << (fileIt->getSize() / 1024) << " kb): " << fileIt->getHash() << std::endl;
		++displayCounter;
	}

	// Totals
	std::cout << std::endl;
	std::cout << "============================================================================" << std::endl;
	std::cout << "Found [" << foundFiles.size() << "] files in [" << (scannerTime / 1000) << "] msec" << std::endl;
	std::cout << "Parsed [" << (totalSize / 1024) << "] kb in [" << (parserTime / 1000) << "] msec" << std::endl;

	// Speeds
	double parserTime_sec = ((double) parserTime / 1000 / 1000);
	if (parserTime_sec == 0) {
		parserTime_sec = 1;
	}
	std::cout << "Parse speed: " << ((totalSize / 1024) / parserTime_sec) << " kb/sec" << std::endl;
	if (foundFiles.size()) {
		std::cout << "Avg file size: " << ((totalSize / 1024) / foundFiles.size()) << " kb" << std::endl;
	} else {
		std::cout << "Avg file size: 0 kb" << std::endl;
	}

	return 0;
}
