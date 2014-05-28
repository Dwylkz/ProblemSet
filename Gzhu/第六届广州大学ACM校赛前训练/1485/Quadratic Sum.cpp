#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)

int n, a;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T, tsu;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        tsu = 0;
        Rep(i, 0, n)
        {
            scanf("%d", &a);
            tsu += a * a;
        }
        printf("%d\n", tsu);
    }
    return 0;
}
