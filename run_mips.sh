#!/bin/bash
qemu-system-mips -nodefaults -M malta -m 256 -nographic -monitor null -serial stdio -bios barebox-flash-image
