#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXN (55000)
#define MAXM (20)

int lca[MAXN << 2];

void LTR()
{

}

struct ST
{
    int t[MAXM][MAXN], n;

    void low(int x)
    {
        int o = 1;
        while ((1 << o) < n) o++;
        return o;
    }

    void ini(int *s, int n)
    {
        int i, j, l = low(n);

        for (i = 0; i < n; i++) t[0][i] = ;
        for (i = 0; i < l; i++)
            for (j = 0; j < n; j++)
    }

    void rmq(int u, int v)
    {
    }
} zkl;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
