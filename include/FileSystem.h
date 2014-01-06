#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Common.h"

#define WINDOWS 0

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define OS WINDOWS
#endif // WINDOWS

namespace FileSystem {
    void createDirectory(const std::string &path);
}

#endif // FILESYSTEM_H
