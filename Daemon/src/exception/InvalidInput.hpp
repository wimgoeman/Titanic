#pragma once

#include "Exception.h"

namespace titanic {
namespace exception {

class InvalidInput : public Exception {
public:
	InvalidInput(const std::string& fieldName, const std::string& expected) :
		Exception("Invalid input for: [" + fieldName + "]. Expected: [" + expected + "]")
	{}

	virtual ~InvalidInput()
	{}

private:
	std::string fieldName;
	std::string expected;
};
}
}