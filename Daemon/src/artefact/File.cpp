#include "File.h"

namespace titanic {
namespace artefact {

File::File(const Poco::File& filePath) : _size(0), _filePath(filePath) {

}


File::~File() {
}

const std::string
File::getPath() const {
	return _filePath.path();
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