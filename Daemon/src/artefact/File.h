#pragma once

#include <string>

#include <Poco/File.h>

namespace titanic {
namespace artefact {

class File {
public:
	File(const Poco::File& filePath);
	virtual ~File();

	const std::string getPath() const;

	const unsigned long getSize() const;

	void setSize(const unsigned long size);

	const std::string& getHash() const;

	void setHash(const std::string& hash);

private:
	unsigned long _size;
	std::string _hash;
	Poco::File _filePath;
};

}
}