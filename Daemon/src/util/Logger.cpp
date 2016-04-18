#include "Logger.h"

#include <Poco/Logger.h>

namespace titanic {
namespace util {

Logger::Logger(const std::string& name) : _name(name), _instance(NULL) {

}

Logger::~Logger() {
	_instance = NULL;
}

Poco::Logger*
Logger::operator->() {
	if (!_instance) {
		_instance = &Poco::Logger::get(_name);
	}
	return _instance;
}

const Poco::Logger*
Logger::operator->() const {
	if (!_instance) {
		_instance = &Poco::Logger::get(_name);
	}
	return _instance;
}

}
}