#pragma once

#include <string>
#include <vector>
#include <Poco/Path.h>

#include "Node.h"
#include "File.h"

namespace titanic {
namespace artefact {

class Directory : public Node {
public:
	Directory(const Poco::Path& path);
	~Directory();

	void scan();

private:
	std::vector<Directory> _subDirectories;
	std::vector<File> _files;
	Poco::Path _absolutePath;
};

}
}