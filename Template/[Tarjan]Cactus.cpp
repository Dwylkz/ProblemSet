#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define MAXI 20001

vector<int> g[MAXI], S;
int n, tim, scc, in[MAXI], out[MAXI];
bool vis[MAXI], inS[MAXI], ok;

void ini()
{
    int i;
    tim = scc = ok = 0;
    S.clear();
    for (i = 0; i < n; i++)
    {
        in[i] = out[i] = 0;
        vis[i] = inS[i] = false;
        g[i].clear();
    }
}

void tarjan(int u)
{
    int i, v, tsu = 0;
    in[u] = out[u] = tim++;
    inS[u] = vis[u] = true;
    S.push_back(u);
    for (i = 0; !ok && i < g[u].size(); i++)
    {
        v = g[u][i];
        if (vis[v] == false)
        {
            tarjan(v);
            if (out[v] < out[u])
                out[u] = out[v];
            if (out[v] < in[u]) tsu++;
        }
        else if (inS[v] == true)
        {
            tsu++;
            if (in[v] < out[u])
                out[u] = in[v];
        }
        if (tsu > 1) ok = 1;
    }
    if (in[u] == out[u])
    {
        scc++;
        do
        {
            v = S[S.size() - 1];
            inS[v] = false;
            S.pop_back();
        } while (u != v);
    }
}

void SCC()
{
    int u;
    for (u = 0; !ok && u < n; u++)
        if (vis[u] == false)
            tarjan(u);
}

int main()
{
    int T, u, v;

    scanf("%d", &T);
    while (T--)
    {
        ini();
        scanf("%d", &n);
        while (scanf("%d%d", &u, &v), u || v)
            g[u].push_back(v);
        SCC();
        puts(scc > 1 || ok? "NO": "YES");
    }
    return 0;
}
