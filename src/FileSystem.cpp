#include "FileSystem.h"

namespace FileSystem {
#if OS == WINDOWS
    void createDirectory(const std::string &path) {
        CreateDirectory(path.c_str(), NULL);
    }
#endif // Windows
}
