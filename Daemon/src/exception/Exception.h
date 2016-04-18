#pragma once

#include <stdexcept>

namespace titanic {
namespace exception {

class Exception : public std::runtime_error {
public:
	Exception(const std::string& what);
	virtual ~Exception();
};

}
}