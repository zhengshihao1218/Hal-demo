// FIXME: your file license if you have one
 
#pragma once
 
#include <android/hardware/foo/1.0/IFoo.h>
#include <hardware/foo.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
 
namespace android::hardware::foo::implementation {
 
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;
 
struct Foo : public V1_0::IFoo {
    // Methods from ::android::hardware::foo::V1_0::IFoo follow.
    Return<int32_t> foo_add(int32_t a, int32_t b) override;
 
    // Methods from ::android::hidl::base::V1_0::IBase follow.
};
 
// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IFoo* HIDL_FETCH_IFoo(const char* name);
 
}  // namespace android::hardware::foo::implementation