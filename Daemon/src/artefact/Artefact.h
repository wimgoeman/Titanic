#pragma once

namespace Poco {
class File;
}

namespace titanic {
namespace artefact {

class Directory;

class Artefact {
public:
	Artefact();
	~Artefact();

	void
		initialize(const Poco::File& directory);

private:
	Directory* _directory;
};
}
}