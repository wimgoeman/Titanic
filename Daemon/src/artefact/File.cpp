#include "File.h"

#include <Poco/Path.h>

namespace titanic {
namespace artefact {

File::File(const Poco::Path& path) : Node ("Booya") {
	_path = Poco::Path::transcode(path.toString());
}


File::~File() {
}

const unsigned long
File::getSize() const {
	return _size;
}

void
File::setSize(const unsigned long size) {
	_size = size;
}

const std::string&
File::getPath() const
{
	return _path;
}

void
File::setPath(const std::string& path)
{
	_path = path;
}

const std::string&
File::getHash() const
{
	return _hash;
}

void
File::setHash(const std::string& hash)
{
	_hash = hash;
}

}
}