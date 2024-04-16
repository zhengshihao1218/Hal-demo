#define ANDROID_FOO_H
#include <hardware/hardware.h>

// 定义模块ID
#define FOO_HARDWARE_MODULE_ID "foo"


// 自己的module，第一个结构体必须是hw_module_t
struct foo_module_t 
{
    struct hw_module_t common;
    
    //可以增加自己的一些属性
    // like
    char * description;
    int methodsZsh;

};

// 自己的device，第一个结构体必须是hw_device_t
struct foo_device_t
{
    struct hw_device_t common;
    int foo_fd;
    int (*foo_add) (int a, int b);
};

