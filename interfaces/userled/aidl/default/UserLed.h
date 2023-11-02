// This library is available on:
// out/soong/.intermediates/device/casa/mojavedroid/interfaces/userled/aidl/
// inside: 
// mojavedroid.hal.userled-V1-ndk_platform-source/gen/include/aidl/mojavedroid/hal/userled
#include <aidl/mojavedroid/hal/userled/BnUserLed.h>

namespace aidl::mojavedroid::hal::userled {
  class UserLed : public BnUserLed {
    public:
      static inline const char RED_LED[] = "/sys/devices/platform/leds/leds/vim3:red/trigger";

    public:
      ndk::ScopedAStatus setMode(const std::string &in_mode, bool *_aidl_return) override;
      static int writeValue(const char *file, const char *value);
  };
}

