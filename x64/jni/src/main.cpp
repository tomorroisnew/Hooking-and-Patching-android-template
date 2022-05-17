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
    HackFunction();
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
