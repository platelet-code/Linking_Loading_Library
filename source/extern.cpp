#include <stdio.h>

namespace myname {
    int var = 42;
}

extern "C" int _ZN6myname3varE;

int main()
{
    printf("%d\n", _ZN6myname3varE);
    return 0;
}



#ifdef __cplusplus
extern "C" {
#endif

void *memset (void *, int, size_t);

#ifdef __cplusplus
}
#endif


// 如果当前编译单元是C++代码, 那么memset会在extern "C"里面被声明; 如果是C代码, 就直接声明.
// 使用__cplusplus这个宏, memset 可以与C语言库中的memset符号进行链接.
