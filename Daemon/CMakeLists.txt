project("Titanic daemon")

set(DAEMON_SOURCES
	"src/main.cpp"
	"src/artefact/Artefact.h"
	"src/artefact/Artefact.cpp"
	"src/artefact/Directory.h"
	"src/artefact/Directory.cpp"
	"src/artefact/File.h"
	"src/artefact/File.cpp"
	"src/interface/TcpServer.h"
	"src/interface/TcpServer.cpp"
	"src/scanner/Scanner.h"
	"src/scanner/Scanner.cpp"
	"src/parser/Parser.h"
	"src/parser/Parser.cpp")

add_executable (titanic_daemon ${DAEMON_SOURCES})
target_link_libraries(titanic_daemon LINK_PRIVATE PocoFoundation)
target_link_libraries(titanic_daemon LINK_PRIVATE PocoNet)
target_compile_features(titanic_daemon PUBLIC cxx_auto_type)