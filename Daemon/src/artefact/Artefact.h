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

private:
	static util::Logger Log;

	Poco::File _path;
	Directory* _directory;
};
}
}