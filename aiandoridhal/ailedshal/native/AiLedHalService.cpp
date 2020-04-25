/*
 * =============================================================================
 *
 *       Filename:  AiLedHalService.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2019 01:08:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (djy), 1449107534@qq.com
 *   Organization:  
 *
 * =============================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <jni.h>
#include <ai_leds_hal.h>

struct ai_led_control_device_t *ai_led_hal_dev = NULL;

static jboolean ai_led_set_on(JNIEnv *env, jobject thiz, jint led)
{
    LOGI("Led HAL JNI: ai_led_set_on() is invoked.");
    if (ai_led_hal_dev == NULL) {
        LOGI("Led HAL JNI: ai_led_hal_dev was not fetched correctly.");
        return -1;
    } else {
        return ai_led_hal_dev->ai_set_on(ai_led_hal_dev, led);
    }
}

static jboolean ai_led_set_off(JNIEnv *env, jobject thiz, jint led)
{
    LOGI("Led HAL JNI: ai_led_set_off() is invoked.");
    if (ai_led_hal_dev == NULL) {
        LOGI("Led HAL JNI: ai_led_hal_dev was not fetched correctly.");
        return -1;
    } else {
        return ai_led_hal_dev->ai_set_off(ai_led_hal_dev, led);
    }
}


static inline int ai_led_control_open(const struct hw_module_t *module,
                                        struct ai_led_control_device_t **device)
{
    LOGE("in ai_led_control_open yes!");
    return module->methods->open(module, 
                                 AI_LED_HARDWARE_MODULE_ID,
                                 (struct hw_device_t **)device);
}

static jboolean ai_led_init(JNIEnv *env, jclass clazz)
{
    struct ai_led_module_t *module;

    LOGE("********** start find hal **********");
    LOGE(AI_LED_HARDWARE_MODULE_ID);
    if (hw_get_module(AI_LED_HARDWARE_MODULE_ID, (const struct hw_module_t **)&module) == 0)
    {
        LOGE("LedService JNI: LED Stub found.");
        if (ai_led_control_open(&module->hw_module, &ai_led_hal_dev) == 0) {
            LOGI("LedService JNI: Got Stub operation.");
            return 0;
        }
    }

    LOGE("LedService JNI: get Stub operations faild.");
    return -1;
}

static const JNINativeMethod methods[] = {
    {"_init", "()Z", (void *)ai_led_init},
    {"_ai_set_on", "(I)Z", (void *)ai_led_set_on},
    {"_ai_set_off", "(I)Z", (void *)ai_led_set_off},
};

int register_led_hal_jni(JNIEnv *env)
{
    static const char * const kClassName = "mobile/android/leds/hal/service/AiLedHalService";
    jclass clazz;

    clazz = env->FindClass(kClassName);
    if (clazz == NULL) {
        LOGE("Can't find class %s\n", kClassName);
        return -1;
    }
    
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != JNI_OK) {
        LOGE("Failed registering methods for %s\n", kClassName);
        return -1;
    }

    return 0;
}

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv *env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **)&env, JNI_VERSION_1_4) != JNI_OK) {
        LOGE("GetEnv failed!");
        return result;
    }

    register_led_hal_jni(env);
    return JNI_VERSION_1_4;
}
