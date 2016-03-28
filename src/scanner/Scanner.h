#pragma once

#include <vector>
#include <string>
#include "FileInfo.h"

namespace titanic {
    namespace scanner {
        class Scanner {
        public:
            std::vector<FileInfo>
            findFiles(const std::string& path);
        };
    }
}