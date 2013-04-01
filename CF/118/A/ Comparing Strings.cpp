#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXC (110000)

int pos[2];
char a[MAXC], b[MAXC];
int main()
{
    #if 0
        freopen("test.txt", "rt", stdin);
    #endif

    while (~scanf("%s%s", &a, &b))
    {
        bool f = 1;
        int la = strlen(a), lb = strlen(b), c = 0;
        if (la != lb)
        {
            puts("NO");
            continue;
        }
        Rep(i, 0, la) if (a[i] != b[i])
        {
            pos[c++] = i;
            if (c > 2)
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            if (a[pos[0]] == b[pos[1]] && a[pos[1]] == b[pos[0]])
                puts("YES");
            else puts("NO");
        }else puts("NO");
    }

    return 0;
}
