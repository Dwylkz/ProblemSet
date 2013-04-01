#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (200)

int vc[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int n, w, id;
    double v, maxf, maxi, ans;

    while (scanf("%d%d", &n, &w), n || w)
    {
        maxf = maxi = 0;
        Clr(vc, MAXN, 0);
        Rep(i, 0, n)
        {
            scanf("%lf", &v);
            vc[id = int(v / w)]++;
            if (vc[id] > maxf) maxf = vc[id];
            if (id > maxi) maxi = id;
        }
        #if 0
            printf("maxf = %lf, maxi = %lf\n", maxf, maxi);
            Rep(i, 0, n) printf(" %d", vc[i]);
            printf("\n");
        #endif
        ans = 0.01;
        Rep(i, 0, maxi + 1) ans += vc[i] *  (maxi - i) / (maxi * maxf);
        printf("%.6lf\n", ans);
    }

    return 0;
}
