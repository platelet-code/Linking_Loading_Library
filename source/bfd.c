#include <stdio.h>
#include "bfd.h"

int main()
{
    const char** t = bfd_target_list();
    while (*t) {
        printf("%s\n", *t);
        t++;
    }
}

// sudo apt-get update
// sudo apt-get install binutils
// sudo apt-get install binutils-dev
// gcc -o target target.c -lbfd
// BFD是一个由GNU项目开发的库，用来处理不同格式的二进制文件，通常用在编译工具和调试器中
