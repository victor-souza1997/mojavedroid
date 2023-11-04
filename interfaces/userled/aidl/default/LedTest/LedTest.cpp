#include <aidl/mojavedroid/hal/userled/IUserLed.h>
#include <android/binder_manager.h>

#include <iostream>
#include <string>

using ::aidl::mojavedroid::hal::userled::IUserLed;


int main(int argc, char *argv[]) {

    std::shared_ptr<IUserLed> mHal;
    std::string a;
    bool c;

    if (argc != 2) {
        std::cout << "USAGE ./LedTest <none|heartbeat|default-on>\n";
        exit(0);
    }

    AIBinder* binder = AServiceManager_waitForService("mojavedroid.hal.userled.IUserLed/default");

    if (binder == nullptr){
        std::cout << "Failed to get cpu service\n";
        exit(-1);
    }

    mHal = IUserLed::fromBinder(ndk::SpAIBinder(binder));

    mHal->setMode(argv[1], &c);
    std::cout << "setScalingGovernor:" << c << std::endl;


    return 0;
}

