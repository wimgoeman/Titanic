#include "Artefact.h"

#include <Poco/File.h>
#include <Poco/Path.h>

#include "Directory.h"
#include "../exception/NotFound.hpp"
#include "../exception/InvalidInput.hpp"
#include "../exception/InsufficientPrivileges.hpp"

namespace titanic {
namespace artefact {

Artefact::Artefact() : _directory(NULL) {

}

Artefact::~Artefact() {
	if (_directory)
		delete _directory;
	_directory = NULL;
}

void
Artefact::initialize(const Poco::File& directory) {
	// Validate input directory
	if (!directory.exists()) {
		throw exception::NotFound(Poco::Path(directory.path()));
	}
	else if (!directory.isDirectory()) {
		throw exception::InvalidInput("directory", "a directory");
	}
	else if (!directory.canRead() || !directory.canWrite()) {
		throw exception::InsufficientPrivileges(Poco::Path(directory.path()));
	}

	// Construct root directory object
	if (_directory)
		delete _directory;
	_directory = NULL;
	_directory = new Directory(Poco::Path(directory.path()).getFileName());
}

}
}