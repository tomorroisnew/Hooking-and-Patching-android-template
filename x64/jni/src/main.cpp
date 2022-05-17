#include <jni.h>
//#include <android/log.h>
#include "libs/KittyMemory/MemoryPatch.h"
#include "libs/64InlineHook/And64InlineHook.hpp"
#include <memory.h>
#include <dlfcn.h>
#include <cstdio>
#include <cstdlib>
#include "exploits/DoSkillDamage.h"
#import "include/Utils.h"

void* hack_thread(void*) {
    LOGI("I have been loaded.");
    // loop until our target library is found
    do {
        sleep(1);
    } while (!get_libBase("libil2cpp.so"));
    LOGI("I found the il2cpp lib. Address is: %p", (void*)get_libBase("libil2cpp.so"));
    LOGI("Calling Main Hack");
    IceWallHack();
    return NULL;
}

void init(){
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

extern "C"
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    init();
    return JNI_VERSION_1_6;
}
