#include <sstream>
#include <Poco/Logger.h>
#include "Logger.h"

#define TITANIC_FATAL(logger, message)								\
if (logger->fatal()) {												\
	std::stringstream stringStream;									\
	stringStream << message;										\
	logger->fatal(stringStream.str(), __FILE__, __LINE__);			\
}

#define TITANIC_CRIT(logger, message)								\
if (logger->critical()) {											\
	std::stringstream stringStream;									\
	stringStream << message;										\
	logger->critical(stringStream.str(), __FILE__, __LINE__);		\
}

#define TITANIC_ERR(logger, message)								\
if (logger->error()) {												\
	std::stringstream stringStream;									\
	stringStream << message;										\
	logger->error(stringStream.str(), __FILE__, __LINE__);			\
}

#define TITANIC_WARN(logger, message)								\
if (logger->warning()) {											\
	std::stringstream stringStream;									\
	stringStream << message;										\
	logger->warning(stringStream.str(), __FILE__, __LINE__);		\
}

#define TITANIC_NOTE(logger, message)								\
if (logger->notice()) {												\
	std::stringstream stringStream;									\
	stringStream << message;										\
	logger->notice(stringStream.str(), __FILE__, __LINE__);			\
}

#define TITANIC_INFO(logger, message)								\
if (logger->information()) {										\
	std::stringstream stringStream;									\
	stringStream << message;										\
	logger->information(stringStream.str(), __FILE__, __LINE__);	\
}

#define TITANIC_DBG(logger, message)								\
if (logger->debug()) {												\
	std::stringstream stringStream;									\
	stringStream << message;										\
	logger->debug(stringStream.str(), __FILE__, __LINE__);			\
}

#define TITANIC_TRC(logger, message)								\
if (logger->trace()) {												\
	std::stringstream stringStream;									\
	stringStream << message;										\
	logger->trace(stringStream.str(), __FILE__, __LINE__);	\
}