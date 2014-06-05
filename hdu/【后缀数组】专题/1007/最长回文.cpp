#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof(c))
#define LLU long long
#define MAXN (330000)
#define MAXT (4400)
#define INFI MAXN
#define SHIFT (1 - 'a')

int rad[MAXN];

void mnc(int *s, int l)
{
    int j = 0, k, mx = 0, id;

    /*for (int i = 1; i < l; i += k)
    {
        for (; s[i - j] == s[i + j]; j++);
        rad[i] = j;
        for (k = 1; k < rad[i] && rad[i - k] != rad[i] - k; k++)
            rad[i + k] = min(rad[i - k], rad[i] - k);
        j = max(j - k, 0);
    }*/
    for (int i = 1; i < l; i++)
    {
        if (mx > i) rad[i] = min(rad[2 * id - i], mx - i);
        else rad[i] = 1;
        while (s[i - rad[i]] == s[i + rad[i]]) rad[i]++;
        if (mx < rad[i] + i)
        {
            mx = rad[i] + i;
            id = i;
        }
    }
}

int str[MAXN], lb, ls;
char buf[MAXN];

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif
    int bt, maxr;

    while (~scanf("%s", buf))
    {
        ls = 0;
        str[ls++] = '$';
        lb = strlen(buf);
        Rep(i, 0, lb)
        {
            str[ls++] = '#';
            str[ls++] = buf[i];
        }
        str[ls++] = '#';
        str[ls++] = 0;
        mnc(str, ls);
        #if 0
            Rep(i, 0, ls) printf(" %c", str[i]);
            puts("");
            Rep(i, 0, ls) printf(" %d", rad[i]);
            puts("");
        #endif
        maxr = 0;
        for (int i = 2; i < ls - 2; i++)
            if (str[i] == '#') maxr = max(maxr, rad[i]);
            else maxr = max(maxr, rad[i]);
        printf("%d\n", maxr - 1);
    }

    return 0;
}
