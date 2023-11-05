#include "UserLed.h"

#include <utils/Log.h>
#include <android-base/logging.h>
#include <sys/stat.h>
#include <string>
#include <sstream>
#include <fstream>
namespace aidl::mojavedroid::hal::userled {

  std::string UserLed::writeValue( const char *filename) {
    LOG(INFO) << "readFile read " << filename;
   
    
    FILE* file = std::fopen(filename, "r");
    if (!file) {
        return ""; // Return an empty string to indicate failure.
    }

    std::string fileContent;
    char buffer[1024]; // Adjust the buffer size as needed.

    while (std::fgets(buffer, sizeof(buffer), file) != NULL) {
        fileContent += buffer;
    }

    std::fclose(file);

    return fileContent;
}

  ndk::ScopedAStatus UserLed::setMode(const std::string &in_mode, std::string *_aidl_return) {
    LOG(INFO) << "UserLed -> setMode data=(" << in_mode.c_str() << ")";
    *_aidl_return = writeValue(RED_LED);//writeValue(RED_LED, in_mode.c_str());

    return ndk::ScopedAStatus::ok();
  }
}

