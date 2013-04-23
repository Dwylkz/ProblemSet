#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define X2(x) (x * x)

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int a, b, c;

    while (scanf("%d%d%d", &a, &b, &c), a || b || c){
        if (X2(a) + X2(b) == X2(c) ||
            X2(a) + X2(c) == X2(b) ||
            X2(c) + X2(b) == X2(a))
        puts("right");
        else puts("wrong");
    }
    return 0;
}
