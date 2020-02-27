# date: 26 Feb 2020
# ref: https://littleosbook.github.io/
# run this builder: . build_cafebabe.sh

# The file loader.s can be compiled into a 32 bits ELF [18] object file with the following command:
nasm -f elf32 loader.s

# Save the linker script into a file called link.ld. The executable can now be linked with the following command:
ld -T link.ld -melf_i386 loader.o -o kernel.elf

# call the qemu emulator and run the kernel.elf
qemu-system-i386 -kernel kernel.elf -curses
# to exit from the qemu command, type ESC+2, then q and <Enter>
