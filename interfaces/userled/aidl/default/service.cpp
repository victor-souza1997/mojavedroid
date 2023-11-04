#define LOG_TAG "mojavedroid.hal.userled"
#include <android-base/logging.h>
#include <android/binder_process.h>
#include <binder/ProcessState.h>

#include <android/binder_manager.h>
#include <binder/IServiceManager.h>

#include "UserLed.h"

using aidl::mojavedroid::hal::userled::UserLed;
using std::string_literals::operator""s;

int main(){
    LOG(INFO) << "UserLed -> TESSSSSSTE";
    const std::string name = UserLed::descriptor + "/default"s;

    android::ProcessState::initWithDriver("/dev/vndbinder");

    ABinderProcess_startThreadPool();

    LOG(INFO) << "UserLed -> Service is starting...";

    std::shared_ptr<UserLed> userLed = ndk::SharedRefBase::make<UserLed>();

    CHECK_EQ(STATUS_OK, AServiceManager_addService(userLed->asBinder().get(), name.c_str()));

    LOG(INFO) << "UserLed -> started...";

    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;  // should not reach
}

