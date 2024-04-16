#define LOG_TAG "Foo"
//#define LOG_NDEBUG 0

#include <hardware/hardware.h>
#include <errno.h>
#include <fcntl.h>
#include <cutils/log.h>
#include <hardware/foo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MODULE_NAME "Foo"
#define MODULE_DES "Foo"
#define MODULE_AUTHOR "ZSH"



// module open or close funcation
static int foo_open(const struct hw_module_t* module, const char* name, struct hw_device_t** device);
static int foo_close(struct hw_device_t* device);

// module funcation method
static int foo_add(int a, int b);

static struct hw_module_methods_t foo_module_methods = 
{
    .open = foo_open
};

// module struct
struct foo_module_t HAL_MODULE_INFO_SYM = 
{
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .version_major = 1,
        .version_minor = 0,
        .id = 	FOO_HARDWARE_MODULE_ID,
        .name = MODULE_NAME,
        .author = MODULE_AUTHOR,
        .methods = &foo_module_methods,
    },
    .description = MODULE_DES,
    .methodsZsh = 3,
};

// module open funcation
static int foo_open(const struct hw_module_t* module, const char* name, struct hw_device_t** device) {
    //1. New a foo_device_t
    if (name == "")
    {
        return -1;
    }
    
    struct foo_device_t* dev;
    dev = (struct foo_device_t*)malloc(sizeof(struct foo_device_t));
    if(!dev) {
        ALOGE("foo open: failed to alloc device space");
        return -EFAULT;
    }
    //2. Set vALUE TO Foo_device_t
    memset(dev, 0, sizeof(struct foo_device_t));
    dev->common.tag = HARDWARE_DEVICE_TAG;
    dev->common.version = 0;
    dev->common.module = (hw_module_t*)module; // set the module
    dev->common.close = foo_close;
    dev->foo_add = foo_add;
    
    // if((dev->foo_fd = open("/dev/hvc0", O_RDWR)) == -1) {
    // 	ALOGE("FOo: open /dev/hvc0 fail-- %s.", strerror(errno));free(dev);
    //     return -EFAULT;
    // }

    *device = &(dev->common);
    ALOGI("Foo open: open driver file successfully");

    return 0;
}
// module close funcation
static int foo_close(struct hw_device_t* device) {
    // 1. device Type change
    struct foo_device_t* foo_device = (struct foo_device_t*) device;

    // 2:free the device memory, close driver file
    if (foo_device) {
    	// close(foo->foo);
        free(foo_device);
    }
    return 0;
}

static int foo_add(int a, int b){
    ALOGI("foo add: value %d + %d",a,b);
    int c = a + b ;
    return c;
}

