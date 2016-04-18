#pragma once

#include "Exception.h"
#include "Poco/Path.h"

namespace titanic {
namespace exception {

class NotFound : public Exception {
public:
	NotFound(const Poco::Path& path) :
		Exception("File or directory not found: " + path.toString()), path(path)
	{}

	virtual ~NotFound() {}

private:
	Poco::Path path;
};

}
}