#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define M 105

int w[256], p[30], q[30];
bool has[1005], vis[1005];

int main()
{
    #if 0
        freopen("test.txt", "rt", stdin);
    #endif
    char s[5];
    int i, j, k, t, ans;
    for (i = 2; i <= 9; i++)
        w[i+'0'] = i;
    w['T'] = 10, w['J'] = 11, w['Q'] = 12;
    w['K'] = 13, w['A'] = 14;
    w['D'] = 0, w['C'] = 1;
    w['H'] = 2, w['S'] = 3;
    scanf ("%d", &t);
    while (t--)
    {
        memset (has, false, sizeof(has));
        for (i = 0; i < 26; i++)
        {
            scanf ("%s", s);
            p[i] = w[s[0]]*10 + w[s[1]];
            has[p[i]] = true;
        }
        k = 0;
        for (i = 2; i <= 14; i++)
        {
            for (j = 0; j <= 3; j++)
            {
                int tp = 10*i + j;
                if (!has[tp]) q[k++] = tp;
            }
        }
        sort (p, p+k);
        sort (q, q+k);
        memset (vis, false, sizeof(vis));
        ans = 0;
        for (i = 0; i < k; i++)
        {
            bool flag = false, win = false;
            int maxs;
            for (j = k - 1; j >= 0; j--)
            {
                if (vis[j]) continue;
                if (!flag) maxs = j, flag = true;
                if (p[i] > q[j])
                {
                    win = true;
                    vis[j] = true;
                    ans++;
                    break;
                }
            }
            if (!win) vis[maxs] = true;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
