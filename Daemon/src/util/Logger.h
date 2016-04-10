#pragma once

#include <string>

namespace Poco {
class Logger;
}

namespace titanic {
namespace util {

class Logger {
public:
	Logger(const std::string& name);
	~Logger();

	const Poco::Logger* operator->() const;
	Poco::Logger* operator->();

private:
	const std::string _name;
	mutable Poco::Logger* _instance;
};
}
}