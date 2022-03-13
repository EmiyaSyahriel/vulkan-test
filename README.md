# World's Smallest Vulkan Compatability Test

Download: [vulkan_test.exe](https://github.com/skeeto/vulkan-test/releases/download/1.0.2/vulkan_test.exe)

This tiny program checks if your Windows system is capable of creating
a Vulkan instance. If not, it will give a hint as to why (missing
drivers, malfunctioning drivers, incompatible drivers).

This began as my initial foray into Vulkan, only to disappoint me that
my hardware isn't supported.
__________________
## Linux Port
EmiyaSyahriel here, The reason why I'm porting the code to Linux, which
already have `vulkaninfo`, is to try my first step into Vulkan in my
free time on my sister's old laptop with Puppy Linux in it and also
a simple functional example to run Vulkan. Well, Vulkan in my hardware
works as intended fortunately, as reported by `vulkaninfo` command.

Most of the code is the same, just uses Unix' `dlfunc` and most of
the string is placed outside of the function scope (it makes the
output binary a bit tidier).

### Requirements
- `build-essentials` package, or at least `gcc` and `strip` 

### Compiling
```
cd <VULKAN TEST DIR>/unix
./compile.sh
./vulkan_test.elf
```