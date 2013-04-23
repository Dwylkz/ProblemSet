#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (300)
#define X2(x) (x * x)

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int n, w, l, v, I[MAXN], maxh;

    while (scanf("%d%d", &n, &w), n || w){
        l = 1;
        maxh = 0;
        memset(I, 0, sizeof I);
        Rep(i, 0, n){
            scanf("%d", &v);
            I[v / w]++;
            l = max(l, v / w);
            maxh =  max(I[v / w], maxh);
        }
        #if 0
            printf("l = %d maxh = %d\n", l, maxh);
        #endif
        double ink = 0.0;
        Rep(i, 0, l + 1) ink += (double)I[i] / maxh * (l - i) / l;
        printf("%.6lf\n", ink + 0.01);
    }
    return 0;
}
