#ifndef UTILS_H
#define UTILS_H

#include <jni.h>
#include <unistd.h>
#include <dlfcn.h>
#include <link.h>


typedef unsigned long DWORD;


DWORD libBase = 0;

/**************************************
	ENTER THE GAME's LIB NAME HERE!
***************************************/
const char* libName = "libil2cpp.so";


DWORD get_libBase(const char* libName);
DWORD getRealOffset(DWORD address);

DWORD addr;
int callback(struct dl_phdr_info *info, size_t size, void *data){
    if(strstr(info->dlpi_name, static_cast<const char* const>(data))){
        addr = info->dlpi_addr;
    }
    return 0;
}

DWORD get_libBase(const char* libName) {
    dl_iterate_phdr(callback, (void*)libName);
    return addr;
}

DWORD getRealOffset(DWORD address) {
	if (libBase == 0) {
		libBase = get_libBase(libName);
	}
	return (libBase + address);
}


#endif
