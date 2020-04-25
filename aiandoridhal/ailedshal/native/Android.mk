LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE_TAGS := eng
LOCAL_MODULE := ai_led_hal_jni
LOCAL_MODULE_PATH := /home/takeno/projects/linux/iTop4412_ICS_git/device/samsung/smdk4x12/ailedshal/native

LOCAL_SRC_FILES := AiLedHalService.cpp

LOCAL_SHARED_LIBRARIES := libandroid_runtime \
						libcutils \
						libhardware \
						libhardware_legacy \
						libnativehelper \
						libsystem_server \
						libutils \
						libui \
						libsurfaceflinger_client

LOCAL_C_INCLUDES += $(JNI_H_INCLUDE) \
					$(LOCAL_PATH)/../hal

LOCAL_PRELINK_MODULE := false
include $(BUILD_SHARED_LIBRARY)
