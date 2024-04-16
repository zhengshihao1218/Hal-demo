
#define LOG_TAG "android.hardware.foo@1.0-service"

#include <android/hardware/foo/1.0/IFoo.h>
#include <hidl/LegacySupport.h>

using android::hardware::foo::V1_0::IFoo;
using android::hardware::defaultPassthroughServiceImplementation;

int main() {
    return defaultPassthroughServiceImplementation<IFoo>();
}

