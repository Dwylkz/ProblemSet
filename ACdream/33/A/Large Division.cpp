#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define LL long long
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c < b; c++)
#define MAXN (440)

char big[MAXN];
int sma;

bool mod(char *a, int b)
{
    int s = 0, l = strlen(a);
    LL tp = 0;

    if (b < 0) b *= -1;
    if (a[0] == '-') s++;
    Rep(i, s, l) tp = (tp + a[i] - '0') % b * 10;
    return tp / 10;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T;

    scanf("%d", &T);
    Rep(C, 1, T + 1)
    {
        scanf("%s%d", big, &sma);
        printf("Case %d: ", C);
        puts(mod(big, sma)? "not divisible": "divisible");
    }
    return 0;
}
