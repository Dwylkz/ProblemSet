#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
typedef long long LL;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, Cas = 1;

    scanf("%d", &T);
    while (T--)
    {
        int ip[8];
        bool yes = 1;
        scanf("%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3);
        Rep(i, 0, 4)
        {
            int ti = 0;
            char b[16];
            scanf("%8s", b);
            Rep(j, 0, 8) ti = (ti << 1) + b[j] - '0';
            if (ti != ip[i]) yes = 0;
            if (i < 3) scanf("%1s", b);
        }
        printf("Case %d: %s\n", Cas++, yes? "Yes": "No");
    }

    return 0;
}
