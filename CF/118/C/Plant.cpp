#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define LL long long
#define MAXN (11000)
#define FF(i, n) for (int i = 0; i < n; i++)
#define M (2)
#define mod (1000000007)

int r[MAXN], ret[M][M], init[M][M], ans[M], ss[M][M] = {3, 1, 1, 0};
double k, t1, t2, w[MAXN];

void ini(int n)
{
    FF(i, n) FF(j, n) init[i][j] = ss[i][j];
}

void matmul(int a[][M], int b[][M], int n)
{
    LL tp[M][M] = {0};
    FF(i, n) FF(k, n) if (a[i][k]) FF(j, n) if (b[k][j])
        tp[i][j] = (tp[i][j] + (LL)a[i][k] * b[k][j]) % mod;
    FF(i, n) FF(j, n) a[i][j] = tp[i][j];
}

void matmul(int a[], int b[][M], int n)
{
    LL tp[M] = {0};
    FF(j, n) if (a[j]) FF(i, n) if (b[i][j])
        tp[i] = (tp[i] + (LL)b[i][j] * a[j]) % mod;
    FF(i, n) a[i] = tp[i];
}

void qmod(int n, LL b)
{
    FF(i, n) FF(j, n) ret[i][j] = (i == j);
    for (; b; b >>= 1)
    {
        if (b & 1) matmul(ret, init, n);
        matmul(init, init, n);
    }
}

int main()
{
    #if 0
        freopen("test.txt", "rt", stdin);
    #endif

    LL n, res, a;
    int dp;

    while (~scanf("%I64d", &n))
    {
        a = 2;
        res = 1;
        while (n)
        {
            if (n & 1) res = res * a % mod;
            n >>= 1;
            a = a * a % mod;
        }
        res = res * (1 + res) / 2 % mod;
        printf("%I64d\n", res);
    }

    return 0;
}
