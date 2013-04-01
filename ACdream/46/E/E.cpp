#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (110)
#define INFI (0x7fffffff)

struct Node
{
    string s;
    int sp, fi;
    friend bool operator < (Node p, Node q)
    {
        return p.s < q.s;
    }
};
map<Node, bool> IQ;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Cas = 1;
    char t[MAXN];
    while(scanf("%s", t), t[0] != '-')
    {
        int fi, len = strlen(t);
        string ts(t);
        Rep(i, 0, len) if (ts[i] == 'F')
        {
            fi = i;
            break;
        }
        queue<Node> Q;
        Node u = {ts, 0, fi};
        IQ.clear();
        Q.push(u);
        IQ[u] = 1;
        bool yes;
        while (!Q.empty())
        {
            bool b = 0, w = 0;
            yes = 1;
            u = Q.front(), Q.pop();
            Rep(i, 0, len)
                if (u.s[i] == 'W') w = 1;
                else if (u.s[i] == 'B')
                {
                    if (b)
                    {
                        if (w)
                        {
                            yes = 0;
                            break;
                        }
                    }
                    else b = 1, w = 0;
                }
            if (yes) break;
            if (u.sp > 9) continue;
            if (0 <= u.fi - 1)
            {
                Node v = {u.s, u.sp + 1, u.fi - 1};
                swap(v.s[u.fi - 1], v.s[u.fi]);
                if (!IQ[v]) IQ[v] = 1, Q.push(v);
            }
            if (u.fi + 1 < len)
            {
                Node v = {u.s, u.sp + 1, u.fi + 1};
                swap(v.s[u.fi], v.s[u.fi + 1]);
                if (!IQ[v]) IQ[v] = 1, Q.push(v);
            }
            if (0 <= u.fi - 2)
            {
                Node v = {u.s, u.sp + 1, u.fi - 2};
                swap(v.s[u.fi - 2], v.s[u.fi]);
                v.s[u.fi] = (v.s[u.fi] == 'B')? 'W': 'B';
                if (!IQ[v]) IQ[v] = 1, Q.push(v);
            }
            if (u.fi + 2 < len)
            {
                Node v = {u.s, u.sp + 1, u.fi + 2};
                swap(v.s[u.fi], v.s[u.fi + 2]);
                v.s[u.fi] = (v.s[u.fi] == 'B')? 'W': 'B';
                if (!IQ[v]) IQ[v] = 1, Q.push(v);
            }
        }
        printf("%d. %d\n", Cas++, yes? u.sp: -1);
    }
    return 0;
}
