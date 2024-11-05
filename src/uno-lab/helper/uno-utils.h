#ifndef UNO_UTILS_H
#define UNO_UTILS_H

#include "ns3/core-module.h"

#include <string>
#include <filesystem>

namespace ns3
{
inline std::string RESULT_DIR = std::string (PROJECT_SOURCE_PATH) + "/data";
void UNOInit();
void CreateFolderIfNotExists(const char* path);
}


#endif