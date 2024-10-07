char *str = "Hello world!\n";

void print()
{
    asm("mov $13, %%edx \n\t"  // 指定要写入的字节数
        "mov %0, %%ecx \n\t"   // 指定要写入的数据的内存地址
        "mov $1, %%ebx \n\t"   // 文件描述符 fd，1 表示标准输出
        "mov $4, %%eax \n\t"   // 系统调用号，4 是 sys_write 在x86 Linux中的调用号
        "int $0x80 \n\t"       // 触发中断，进行系统调用
        :
        : "r" (str)
        : "edx", "ecx", "ebx", "eax"  // 列出所有会被这段 asm 修改的寄存器
    );
}

void custom_exit()
{
    asm(
        "mov $0, %%ebx \n\t"  // exit code，0 表示正常退出
        "mov $1, %%eax \n\t"  // 系统调用号，1 是 sys_exit 在x86 Linux中的调用号
        "int $0x80 \n\t"      // 触发中断，进行系统调用
        :
        :
        : "ebx", "eax"        // 列出所有会被这段 asm 修改的寄存器
    );
}

void nomain()
{
    print();
    custom_exit();
}


// gcc -m32 -static -nostdlib -e nomain -o TinyHelloWorld TinyHelloWorld.o
// ld -m elf_i386 -static -e nomain -o TinyHelloWorld TinyHelloWorld.o
