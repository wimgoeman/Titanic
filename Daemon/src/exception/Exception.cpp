#include "Exception.h"

namespace titanic {
namespace exception {

Exception::Exception(const std::string& what) : std::runtime_error(what)
{}

Exception::~Exception()
{}

}
}