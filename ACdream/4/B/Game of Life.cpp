#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXM (1024)

int m, t;
char B[2][MAXM][MAXM];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Case, Xor, cb, cw;

    scanf("%d", &Case);
    while (Case--)
    {
        scanf("%d%d", &m, &t);
        Rep(i, 0, m)
        {
            scanf("%s", B[0][i]);
            Rep(j, 0, m) B[0][i][j] = B[1][i][j] = (B[0][i][j] == 'b');
        }
        Xor = 0;
        while (t--)
        {
            Rep(i, 1, m - 1) Rep(j, 1, m - 1)
            {
                cb = 0;
                cw = 0;
                Rep(k, i - 1, i + 2) Rep(l, j - 1, j + 2)
                    //if (k != i && l != j)
                    {
                        if (B[Xor][k][l]) cb++;
                        else cw++;
                    }
                B[Xor ^ 1][i][j] = (cb > cw);
            }
            Xor ^= 1;
        }
        cb = 0;
        cw = 0;
        Rep(i, 0, m) Rep(j, 0, m)
            if (B[Xor][i][j]) cb++;
            else cw++;
        printf("%d %d\n", cb, cw);
        #if 0
            Rep(i, 0, m)
            {
                Rep(j, 0, m) putchar(B[Xor][i][j]? 'b': 'w');
                puts("");
            }
        #endif
    }
    return 0;
}
