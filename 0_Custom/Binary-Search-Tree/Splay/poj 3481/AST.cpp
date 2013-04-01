#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (2000002)

struct SLY
{
    typedef int TI[MAXN];
    TI p, ky, c, k, ct;
    int rt, id, s[MAXN][2];
    int cre(int key, int cli = 0, int fa = 0)
    {
        p[id] = fa;
        ky[id] = key;
        s[id][0] = s[id][1] = 0;
        c[id] = 1;
        ct[id] = cli;
        return id++;
    }
    SLY()
    {
        cre(id = 0);
    }
    void ini()
    {
        id = 1;
        rt = 0;
    }
    void rot(int x, bool b)
    {
        int y = s[x][!b];
        s[x][!b] = s[y][b];
        if (s[y][b]) p[s[y][b]] = x;
        p[y] = p[x];
        if(!p[x]) rt = y;
        else s[p[x]][s[p[x]][0] != x] = y;
        s[y][b] = x;
        p[x] = y;
    }
    void sly(int x, int y = 0)
    {
        bool bp = (s[p[x]][0] != x);
        while (p[x] != y)
        {
            if (p[p[x]] == y)
            {
                rot(p[x], !bp);
                break;
            }
            bool bg = (s[p[p[x]]][0] != p[x]);
            if (bg ^ bp) rot(p[x], bg);
            else rot(p[p[x]], !bg);
            rot(p[x], !bg);
        }
    }
    int ins(int cli, int key)
    {
        if (!rt)
        {
            rt = cre(key, cli);
            return rt;
        }
        bool lr;
        int y = 0, x = rt;
        while (x && ky[x] != key)
        {
            y = x;
            x = s[x][lr = key > ky[x]];
        }
        if (x) c[x]++;
        else s[y][lr] = x = cre(key, cli, y);
        sly(x);
        return x;
    }
    void del(int x)
    {
        if (!x) return ;
        if (--c[x]) return ;
        sly(x);
        if (!s[rt][0])
        {
            if (s[rt][1]) p[s[rt][1]] = 0;
            rt = s[rt][1];
        }
        else
        {
            sly(ext(s[rt][0], 1));
            s[rt][1] = s[s[rt][1]][1];
            if (s[rt][1]) p[s[rt][1]] = 0;
        }
    }
    int ext(int x, bool b)
    {
        while (x && s[x][b]) x = s[x][b];
        return x;
    }
    void tra(int x)
    {
        if (!rt) return ;
        if (s[x][0]) tra(s[x][0]);
        printf("Tra %4d->(%4d, %4d)\n", ky[x], ky[s[x][0]], ky[s[x][1]]);
        if (s[x][1]) tra(s[x][1]);
    }
} zkl;

int n;

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int op;
    zkl.ini();
    while (scanf("%d", &op), op)
        if (op == 1)
        {
            int k, p;
            scanf("%d%d", &k, &p);
            zkl.ins(k, p);
            #if 0
                printf("Ins %d %d:\n", k, p);
                zkl.tra(zkl.rt);
            #endif
        }
        else
        {
            int x = zkl.ext(zkl.rt, op == 2);
            printf("%d\n", x? zkl.ct[x]: 0);
            zkl.del(x);
        }

    return 0;
}
