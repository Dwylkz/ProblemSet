#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (220000)
#define INFI (512)

struct SA
{
    int sa[MAXN], rank[MAXN], height[MAXN];
    int wa[MAXN], wb[MAXN], wv[MAXN], wd[MAXN];

    int cmp(int *r, int a, int b, int l){
        return r[a] == r[b] && r[a+l] == r[b+l];
    }

    void ini(int *r, int l, int m)
    {
        da(r, l, m);
        calHeight(r, l - 1);
    }

    void da(int *r, int n, int m){          //  倍增算法 r为待匹配数组  n为总长度 m为字符范围
        int i, j, p, *x = wa, *y = wb, *t;
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
        for(j = 1, p = 1; p < n; j *= 2, m = p){
            for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
            for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
            for(i = 0; i < n; i ++) wv[i] = x[y[i]];
            for(i = 0; i < m; i ++) wd[i] = 0;
            for(i = 0; i < n; i ++) wd[wv[i]] ++;
            for(i = 1; i < m; i ++) wd[i] += wd[i-1];
            for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
            for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){
                x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
            }
        }
    }

    void calHeight(int *r, int n){           //  求height数组。
        int i, j, k = 0;
        for(i = 1; i <= n; i ++) rank[sa[i]] = i;
        for(i = 0; i < n; height[rank[i ++]] = k){
            for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
        }
    }
} zkl;

char A[MAXN], B[MAXN];
int str[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int la, lb, maxi, l;

    while (~scanf("%s", A))
    {
        scanf("%s", B);
        la = strlen(A);
        lb = strlen(B);
        l = 0;

        Rep(i, 0, la) str[l++] = A[i] - 'a' + 1;
        str[l++] = 29;
        Rep(i, 0, lb) str[l++] = B[i] - 'a' + 1;
        str[l++] = 0;
        zkl.ini(str, l, 256);
        maxi = 0;
        Rep(i, 1, l)
            if ((zkl.sa[i] < la && zkl.sa[i - 1] > la) || (zkl.sa[i - 1] < la && zkl.sa[i] > la))
                if (zkl.height[i] > maxi) maxi = zkl.height[i];
        #if 0
            printf(" ");
            Rep(i, 0, l) putchar(str[i] + 'a' - 1);
            putchar('\n');
            Rep(i, 0, l)
            {
                printf("  ");
                Rep(j, zkl.sa[i], l) putchar(str[j] + 'a' - 1);
                putchar('\n');
            }
            Rep(i, 0, l) printf(" %d", zkl.height[i]);
            putchar('\n');
        #endif
        printf("%d\n", maxi);
    }

    return 0;
}
