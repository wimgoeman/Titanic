#include "Scanner.h"
#include <Poco/RecursiveDirectoryIterator.h>

namespace titanic {
    namespace scanner {
        std::vector<artefact::File>
        Scanner::findFiles(const std::string& path) {
            std::vector<artefact::File> foundFiles;

            Poco::RecursiveDirectoryIterator<Poco::ChildrenFirstTraverse> dirIt(path);
            Poco::RecursiveDirectoryIterator<Poco::ChildrenFirstTraverse> dirEnd;
            for (; dirIt != dirEnd; ++dirIt) {
                artefact::File fileInfo(dirIt->path());
                foundFiles.push_back(fileInfo);
            }

            return foundFiles;
        }
    }
}