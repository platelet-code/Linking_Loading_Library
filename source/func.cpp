#include <iostream>

int func(int x) { return x; }
float func(float x) { return x; }

class C {
public:
    int func(int x) { return x; }
    class C2 {
    public:
        int func(int x) { return x; }
    };
};

namespace N {
    int func(int x) { return x; }
    class C {
    public:
        int func(int x) { return x; }
    };
}

int main() {
    func(10);
    func(10.0f);
    C c;
    c.func(10);
    C::C2 c2;
    c2.func(20);
    N::func(30);
    N::C n_c;
    n_c.func(40);
    return 0;
}

// C++允许多个不同参数类型的函数拥有一样的名字, 就是所谓的函数重载. 另外C++还在语言级别支持名称空间, 即允许在不同的名称空间有多个同样名字的符号.
// _Z4funcf               c++filt _Z4funcf  -> func(float)
// _Z4funci               c++filt _Z4funci  -> func(int)
// _ZN1C2C24funcEi        c++filt _ZN1C2C24funcEi -> C::C2::func(int)
// _ZN1C4funcEi           c++filt _ZN1C4funcE  ->  C::func(int)
// _ZN1N1C4funcEi         c++filt _ZN1N1C4funcEi  ->  N::C::func(int)
// _ZN1N4funcEi           c++filt _ZN1N4funcEi  ->  N::func(int)
// 函数签名包含一个函数的信息, 包括函数名, 它的参数类型, 它所在的类和名称空间及其他信息.
