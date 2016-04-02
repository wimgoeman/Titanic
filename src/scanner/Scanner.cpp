#include "Scanner.h"
#include <Poco/RecursiveDirectoryIterator.h>

namespace titanic {
    namespace scanner {
        std::vector<FileInfo>
        Scanner::findFiles(const std::string& path) {
            std::vector<FileInfo> foundFiles;

            Poco::RecursiveDirectoryIterator<Poco::ChildrenFirstTraverse> dirIt(path);
            Poco::RecursiveDirectoryIterator<Poco::ChildrenFirstTraverse> dirEnd;
            for (; dirIt != dirEnd; ++dirIt) {
                FileInfo fileInfo(dirIt->path());
                foundFiles.push_back(fileInfo);
            }

            return foundFiles;
        }
    }
}