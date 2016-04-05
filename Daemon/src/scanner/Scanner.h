#pragma once

#include <vector>
#include <string>
#include "../artefact/File.h"

namespace titanic {
    namespace scanner {
        class Scanner {
        public:
            std::vector<artefact::File>
            findFiles(const std::string& path);
        };
    }
}