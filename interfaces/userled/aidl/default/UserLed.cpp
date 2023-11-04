#include "UserLed.h"

#include <utils/Log.h>
#include <android-base/logging.h>
#include <sys/stat.h>

namespace aidl::mojavedroid::hal::userled {

  int UserLed::writeValue(const char *file, const char *value) {

    int fd;
    int str_len = strlen(value) + 1;

    fd = open(file, O_WRONLY);

    if (fd < 0) {
      return -1;
    }

    if(!write(fd, value, str_len)){
      close(fd);
      return -1;
    }  

    close(fd);
    return 0;
  }

  ndk::ScopedAStatus UserLed::setMode(const std::string &in_mode, bool *_aidl_return) {
    LOG(INFO) << "UserLed -> setMode data=(" << in_mode.c_str() << ")";
    *_aidl_return = this->writeValue(RED_LED, in_mode.c_str()) == 0;

    return ndk::ScopedAStatus::ok();
  }
}

