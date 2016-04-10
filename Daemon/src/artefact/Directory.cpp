#include "Directory.h"

#include <Poco/RecursiveDirectoryIterator.h>

namespace titanic {
namespace artefact {

Directory::Directory(const Poco::Path& path) : Node("TODO remove NODE class"), _absolutePath(path) {
	if (!_absolutePath.isAbsolute())
		_absolutePath.makeAbsolute();
}

Directory::~Directory() {

}

void
Directory::scan() {
	Poco::RecursiveDirectoryIterator<Poco::SiblingsFirstTraverse> dirIt(_absolutePath);
	Poco::RecursiveDirectoryIterator<Poco::SiblingsFirstTraverse> dirEnd;
	for (; dirIt != dirEnd; ++dirIt) {
		if (dirIt->isFile()) {

		} else if (dirIt->isDirectory()) {
			_subDirectories.push_back(dirIt.path());
		} else {
			// TODO: Log a warning
		}

		Poco::Path path;
	}

}

}
}