// FIXME: your file license if you have one
 
#include "Foo.h"
#include <log/log.h>
 
namespace android::hardware::foo::V1_0::implementation {
 
Foo::Foo(foo_device_t *device) {
    mDevice = device;
}
 
// Methods from ::android::hardware::foo::V1_0::IFoo follow.
Return<int32_t> Foo::foo_add(int32_t a, int32_t b) {
     
    return mDevice->foo_add(a,b);
  
}
 
 
// Methods from ::android::hidl::base::V1_0::IBase follow.
 
IFoo* HIDL_FETCH_IFoo(const char* /* name */) {
    foo_device_t *dev;
    const hw_module_t *hw_module = NULL;
 
    int32_t ret = hw_get_module(FOO_HARDWARE_MODULE_ID, &hw_module);
    if (ret != 0) {
        ALOGE("hw_get_module %s failed: %d", FOO_HARDWARE_MODULE_ID, ret);
        return nullptr;
    }
    ret = hw_module->methods->open(hw_module, "FOO_HARDWARE", (hw_device_t **) &dev);
    if (ret < 0) {
        ALOGE("Can't open Foo hardware, error: %d", ret);
        return nullptr;
    }
    return new Foo(dev);
}
//
}  // namespace android::hardware::foo::implementation