#pragma once

#include <Poco/File.h>
#include "../util/Logger.h"

namespace titanic {
namespace artefact {

class Directory;

class Artefact {
public:
	Artefact(const Poco::File& path);
	~Artefact();

	void initialize();

	void scan();

	unsigned long countFiles() const;

	unsigned long countDirectories() const;

	unsigned long countAll() const;

private:
	static util::Logger Log;

	void reset();

	Poco::File _path;
	Directory* _directory;
};
}
}