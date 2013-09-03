#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN 1100000

struct MiQ
{
    int h, e, q[MAXN], t[MAXN];
    void ini()
    {
        h = e = 0;
    }
    void ins(int tq, int tt)
    {
        for (; e > h && q[e - 1] > tq; e--);
        q[e] = tq;
        t[e++] = tt;
    }
    int pop(int tt)
    {
        if (t[h] < tt) h++;
        return q[h];
    }
} miq;

struct MxQ
{
    int h, e, q[MAXN], t[MAXN];
    void ini()
    {
        h = e = 0;
    }
    void ins(int tq, int tt)
    {
        for (; e > h && q[e - 1] < tq; e--);
        q[e] = tq;
        t[e++] = tt;
    }
    int pop(int tt)
    {
        if (t[h] < tt) h++;
        return q[h];
    }
} mxq;

int n, k, a, mx[MAXN], mi[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    miq.ini();
    mxq.ini();
    scanf("%d%d", &n, &k);
    Rep(i, 0, k)
    {
        scanf("%d", &a);
        miq.ins(a, i);
        mxq.ins(a, i);
    }
    mi[0] = miq.pop(0);
    mx[0] = mxq.pop(0);
    Rep(i, k, n)
    {
        scanf("%d", &a);
        miq.ins(a, i);
        mxq.ins(a, i);
        mi[i - k + 1] = miq.pop(i - k + 1);
        mx[i - k + 1] = mxq.pop(i - k + 1);
    }
    Rep(i, 0, n - k + 1)
    {
        printf("%d", mi[i]);
        if (i < n - k)
            putchar(' ');
    }
    puts("");
    Rep(i, 0, n - k + 1)
    {
        printf("%d", mx[i]);
        if (i < n - k)
            putchar(' ');
    }
    puts("");

    return 0;
}
