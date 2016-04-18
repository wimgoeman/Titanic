#include "Parser.h"

#include <fstream>
#include <Poco/MD5Engine.h>
#include <Poco/DigestStream.h>
#include <Poco/StreamCopier.h>

namespace titanic {
namespace parser {

Parser::Parser(const std::string& path) : _size(0), _path(path)
{}

Parser::~Parser()
{}

bool
Parser::parse() {
	std::ifstream istream(_path, std::ios::binary);
	if (!istream)
	{
		return false;
	}

	Poco::MD5Engine md5Engine;
	Poco::DigestOutputStream digestStream(md5Engine);

	std::streamsize streamSize = Poco::StreamCopier::copyStream(istream, digestStream);
	digestStream.close();

	_size = (unsigned long) streamSize;
	_hash = Poco::DigestEngine::digestToHex(md5Engine.digest());
	return true;
}

const unsigned long
Parser::getSize() const {
	return _size;
}

const std::string&
Parser::getHash() const {
	return _hash;
}

const std::string&
Parser::getPath() const {
	return _path;
}

void
Parser::setPath(const std::string& path) {
	if (_path != path) {
		_hash = "";
		_size = 0;
	}
	_path = path;
}

}
}