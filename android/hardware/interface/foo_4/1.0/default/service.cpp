
#define LOG_TAG "android.hardware.foo@1.0-service"

#include <android/hardware/foo/1.0/IFoo.h>
#include <hidl/HidlTransportSupport.h>
#include <hidl/LegacySupport.h>
#include <log/log.h>
#include "Foo.h"

using ::android::OK;
using android::hardware::joinRpcThreadpool;
using android::hardware::foo::V1_0::IFoo;
using android::hardware::configureRpcThreadpool;
using android::hardware::foo::implementation::Foo;
using android::sp;

int main() {
    // return defaultPassthroughServiceImplementation<IFoo>();
    sp<IFoo> foo = new Foo();
    configureRpcThreadpool(1, true /* will join */);
    if (foo->registerAsService() != OK) {
        ALOGE("Could not register foo 1.0 service.");
        return 1;
    }
    joinRpcThreadpool();

    ALOGE("Service exited!");
    return 1;
}

