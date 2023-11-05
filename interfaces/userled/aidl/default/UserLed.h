// This library is available on:
// out/soong/.intermediates/device/casa/mojavedroid/interfaces/userled/aidl/
// inside: 
// mojavedroid.hal.userled-V1-ndk_platform-source/gen/include/aidl/mojavedroid/hal/userled
#include <aidl/mojavedroid/hal/userled/BnUserLed.h>

namespace aidl::mojavedroid::hal::userled {
  class UserLed : public BnUserLed {
    public:
      static inline const char RED_LED[] = "/sys/bus/iio/devices/iio:device0/in_humidityrelative_scale";

    public:
      ndk::ScopedAStatus setMode(const std::string &in_mode, std::string *_aidl_return) override;
      
      static std::string writeValue(const char *file);
  };
}

