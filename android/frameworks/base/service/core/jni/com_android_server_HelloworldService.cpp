#define LOG_TAG "HellowroldService"

#include <nativehelper/JNIHelp.h>
#include "jni.h"
#include "android_runtime/AndroidRuntime.h"
#include <utils/misc.h>
// #include <utils/Log.h>
#include <log/log.h>
#include <hardware/hardware.h>
// #include <hardware/helloworld.h>
#include <android/hardware/foo/1.0/IFoo.h>
#include <binder/IServiceManager.h>
#include <stdio.h>

using android::sp;
using android::hardware::foo::V1_0::IFoo;

namespace android {
    // struct helloworld_device_t* helloworld_device = NULL;

    // static jboolean helloworld_init(JNIEnv* env, jclass clazz) {
    //     helloworld_module_t * module;

    //     if(hw_get_module(HELLOWORLD_HARDWARE_MODULE_ID, (const struct hw_module_t **)&module) ==0) {
    //         if (module->common.methods->open(&(module->common), HELLOWORLD_HARDWARE_MODULE_ID, (struct hw_device_t **)&helloworld_device) == 0) {
    //             return 0;
    //         }
    //         return -1;
    //     }
    //     return -1;
    // }

    // static jint helloworld_AddVal(JNIEnv* env, jobject clazz, jint a, jint b) {
    //     int result;
    //     if(!helloworld_device) {
    //         return -1;
    //     } 
    //     helloworld_device->helloworld_add(helloworld_device,a,b,&result);
    //     return result;
    // }

    sp<IFoo> hw_device;
    static jboolean helloworld_init(JNIEnv* env, jclass clazz) {
        hw_device = IFoo::getService();
        if(hw_device == nullptr) {
            ALOGW("...failed to get IFoo service");
            return -1;
        }
        return 0;
    }

    static jint helloworld_AddVal(JNIEnv* env, jobject clazz, jint a, jint b) {
        int result;
        if(!hw_device) {
            return -1;
        }
        result = hw_device->foo_add(a,b);
        return result;
    }

    static JNINativeMethod sMethods[] = {
   // 将Java中的一个方法（init）与本地（C/C++）代码中的helloworld_init函数进行绑定。
   // 结构体定义
   // typedef struct {
   // const char* name;      // Java中的方法名
   // const char* signature; // 方法签名
   // void*       fnPtr;     // 对应的C/C++函数
   // } JNINativeMethod;
   // "init"：这是Java中的方法名
   // "()Z"：这是Java方法的签名。在这个例子中，它表示这个方法没有参数，并返回一个boolean值。 (II)I: 输入输出都是int
   // (void*)helloworld_init：这是native代码中的函数
        {"init","()Z",(void*)helloworld_init},
        {"addValue","(II)I",(void*)helloworld_AddVal},
    };

    int register_android_server_HelloworldService(JNIEnv* env)
    {
        return jniRegisterNativeMethods(env, "com/android/server/HelloWorldService", sMethods, NELEM(sMethods));
    };
    
}
