#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (26)

int mov[3][4] = {{1, 3, 4, 2}, {0, 2, 5, 3}, {0, 3, 5, 1}};
int r, c;

int spo(int pre, int now, int det)
{
    int tno, pos;

    if (now > 2)
    {
        tno = 5 - now;
        det *= -1;
    }
    else tno = now;
    Rep(i, 0, 4) if (mov[tno][i] == pre)
        pos = (i + det + 4) % 4;

    return pos;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int ans, now, pos, pre, lr;

    pre = 3;
    lr = 1;
    ans = now = pos = 0;
    scanf("%d%d", &r, &c);
    Rep(i, 0, r)
    {
        #if 1
            printf(" %d", now + 1);
        #endif
        ans += c / 4 * 7;
        Rep(j, 0, c % 4)
        {
            ans += now;
            pos = spo(pre, now, 2);
            pre = 5 - now;
            now = mov[now > 2? (5 - now): now][pos];
        }
        ans += now;
        pos = spo(pre, now, lr * 1);
        now = mov[now > 2? (5 - now): now][pos];
        pos = spo(pre, now, 2);
        pre = mov[now > 2? (5 - now): now][pos];
        ans += now;
        lr *= -1;
    }
    #if 1
        printf("\n");
    #endif
    printf("%d\n", ans);

    return 0;
}
