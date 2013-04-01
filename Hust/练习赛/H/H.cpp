#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, a, b, c, Cas = 1;

    while (~scanf("%d%d%d", &a, &b, &c))
    {
        if (c * (a - b) % b) c = c * (a - b) / b + 1;
        else c = c * (a - b) / b;
        printf("%d\n", c);
    }

    return 0;
}
