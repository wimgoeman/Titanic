#include "FileInfo.h"

#include <Poco/Path.h>

namespace titanic {
namespace scanner {

FileInfo::FileInfo(const Poco::Path& path)
{
	_path = Poco::Path::transcode(path.toString());
}


FileInfo::~FileInfo()
{
}

const unsigned long
FileInfo::getSize() const {
	return _size;
}

void
FileInfo::setSize(const unsigned long size) {
	_size = size;
}

const std::string&
FileInfo::getPath() const
{
	return _path;
}

void
FileInfo::setPath(const std::string& path)
{
	_path = path;
}

const std::string&
FileInfo::getHash() const
{
	return _hash;
}

void
FileInfo::setHash(const std::string& hash)
{
	_hash = hash;
}

}
}