LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_LDFLAGS := -Wl,--build-id
LOCAL_MODULE := JniUtil

LOCAL_SRC_FILES := \
	aes256.c \
	base64.c \
	JniUtil.c \
	JniLib.cpp

MODULE_CPPFLAGS:= -std=c++11
LOCAL_LDLIBS += -llog

LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_PROGUARD_ENABLED:= disabled
include $(BUILD_SHARED_LIBRARY)