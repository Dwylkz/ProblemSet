#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, Cas = 1;

    scanf("%d", &T);
    while (T--)
    {
        LL n, m;
        scanf("%lld%lld", &n, &m);
        n = n * ((n / m) % 2? -1: 1);
        printf("Case %d: %lld\n", Cas++, n / 2 * m);
    }

    return 0;
}
