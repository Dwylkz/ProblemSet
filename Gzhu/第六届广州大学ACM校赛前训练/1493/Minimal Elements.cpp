#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (100000)
#define INFI (0x7fffffff)

struct Node
{
    int x, y, z;

    friend bool operator < (Node a, Node b)
    {
        if (a.x == b.x)
        {
            if (a.y == b.y)
                return a.z > b.z;
            return a.y > b.y;
        }
        return a.x > b.x;
    }
} S[MAXN];

int n, x, y, z;


int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T;

    while (~scanf("%d", &n))
    {
        Rep(i, 0, n)
            scanf("%d%d%d", &S[i].x, &S[i].y, &S[i].z);
        sort(S, S + n);
    }
    return 0;
}
