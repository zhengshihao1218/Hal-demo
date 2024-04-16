hardware_modules := \
    camera \
    gralloc \
    sensors \
    foo # add foo moudle by Shihao.zheng
include $(call all-named-subdir-makefiles,$(hardware_modules))
