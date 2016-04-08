#pragma once

#include <string>
#include <vector>

#include "Node.h"
#include "File.h"

namespace titanic {
namespace artefact {

class Directory : public Node {
public:
	Directory(const std::string& name);
	~Directory();

private:
	std::vector<Directory> _subDirectories;
	std::vector<File> _files;
};

}
}