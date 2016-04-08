#pragma once

#include <Poco/Path.h>

#include "Exception.h"

namespace titanic {
namespace exception {

class InsufficientPrivileges : public Exception {
public:
	InsufficientPrivileges(const Poco::Path& path) :
		Exception("Insufficient privileges for [" + path.toString() + "]"),
		path(path)
	{}

	virtual ~InsufficientPrivileges()
	{}

private:
	Poco::Path path;
};
}
}