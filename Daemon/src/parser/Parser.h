#pragma once

#include <string>

namespace titanic {
namespace parser {

class Parser {
public:
	Parser(const std::string& path);
	~Parser();

	bool parse();

	const unsigned long getSize() const;

	const std::string& getHash() const;

	const std::string& getPath() const;
	void setPath(const std::string& path);

private:
	unsigned long _size;
	std::string _path;
	std::string _hash;
};

}
}