#include "Artefact.h"

#include <Poco/File.h>
#include <Poco/Path.h>

#include "Directory.h"
#include "../exception/NotFound.hpp"
#include "../exception/InvalidInput.hpp"
#include "../exception/InsufficientPrivileges.hpp"
#include "../util/LoggerMacros.hpp"

namespace titanic {
namespace artefact {

util::Logger Artefact::Log("titanic.artefact");

Artefact::Artefact(const Poco::File& path) : _directory(NULL), _path(path) {
	TITANIC_DBG(Log, "Artefact created on [" + path.path() + "]");
}

Artefact::~Artefact() {
	if (_directory)
		delete _directory;
	_directory = NULL;
	TITANIC_DBG(Log, "Artefact destroyed");
}

void
Artefact::initialize() {
	TITANIC_DBG(Log, "Initializing artefact");

	// Validate input directory
	if (!_path.exists()) {
		throw exception::NotFound(Poco::Path(_path.path()));
	}
	else if (!_path.isDirectory()) {
		throw exception::InvalidInput("directory", "a directory");
	}
	else if (!_path.canRead() || !_path.canWrite()) {
		throw exception::InsufficientPrivileges(Poco::Path(_path.path()));
	}

	// Construct root directory object
	if (_directory)
		delete _directory;
	_directory = NULL;
	_directory = new Directory(Poco::Path(_path.path()).getFileName());

	TITANIC_DBG(Log, "Artefact initialized");
}

void
Artefact::scan() {
	if (!_directory) {
		throw exception::Exception("Not initialized");
	}

	_directory->scan();
}

}
}