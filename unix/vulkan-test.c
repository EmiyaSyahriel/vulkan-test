#include <dlfcn.h>
#include <stdio.h>

const char* names[3] = {
    "libvulkan.so.1",
    "vkGetInstanceProcAddr",
    "vkCreateInstance"
};

const char* msgs[5] = {
    "Vulkan library not found",
    "Vulkan incompatible : No vkGetInstanceProcAddr",
    "Vulkan incompatible : No vkCreateInstance",
    "Vulkan malfunction : Instance creation failed",
    "Vulkan should works as expected."
};

#define REPORT(code, msg) {\
    printf("%s\n", msg);\
    if(vk) dlclose(vk);\
    return code;\
}

int main(const char** argv, int argc){
	void* vk = dlopen(names[0], RTLD_LAZY | RTLD_GLOBAL);
	if(!vk) REPORT(-1, msgs[0]);
	void *(*vkGetInstanceProcAddr)(void*, const char*) = dlsym(vk, names[1]);
	if(!vkGetInstanceProcAddr) REPORT(-1, msgs[1]);
	int (*vkCreateInstance)(int*, void*, void**) = vkGetInstanceProcAddr(0, names[2]);
	if(!vkCreateInstance) REPORT(-1, msgs[2]);
	void* instance = 0;
	int result = vkCreateInstance((int[16]){1}, 0, &instance );
	if(!instance || result != 0)
		REPORT(-1, msgs[3]);
	REPORT(0, msgs[4]);
}