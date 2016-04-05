project("Titanic agent")

set(AGENT_SOURCES
	"src/main.cpp"
	"src/interface/TcpClient.h"
	"src/interface/TcpClient.cpp")

add_executable (titanic_agent ${AGENT_SOURCES})
target_link_libraries(titanic_agent LINK_PRIVATE PocoFoundation)
target_link_libraries(titanic_agent LINK_PRIVATE PocoNet)
target_compile_features(titanic_agent PUBLIC cxx_auto_type)