#pragma once

#include <vector>
#include <Poco/File.h>

#include "../util/Logger.h"
#include "File.h"

namespace titanic {
namespace artefact {

class Directory {
public:
	Directory(const Poco::File& directoryPath);
	~Directory();

	void scan();

	unsigned long countFiles() const;

	unsigned long countDirectories() const;

	unsigned long countAll() const;

private:
	static util::Logger Log;

	void reset();

	std::vector<Directory*> _subDirectories;
	std::vector<File*> _files;
	Poco::File _directoryPath;
};

}
}