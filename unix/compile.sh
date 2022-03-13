#!/bin/sh

gcc -o ./vulkan_test_d.elf -rdynamic -Wl,--no-as-needed -ldl ./vulkan-test.c
strip -o ./vulkan_test.elf ./vulkan_test_d.elf
rm ./vulkan_test_d.elf
chmod +x ./vulkan_test.elf