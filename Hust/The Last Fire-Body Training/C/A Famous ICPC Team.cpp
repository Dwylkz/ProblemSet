#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (4)

int A[MAXN];

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int Cas = 1;

    while (~scanf("%d%d%d%d", A, A + 1, A + 2, A + 3))
    {
        sort(A, A + 4);
        /*double l = A[2] + A[3], dl = sqrt(A[2] / 2.0) + sqrt(A[2] / 4.0);
        if (dl < A[2] &&
            A[0] <= A[3] - sqrt(A[2]) / 2.0 &&
            A[1] <= A[3] - sqrt(A[2]) / 2.0)
            l = A[3] + dl;*/
        printf("Case %d: %d\n", Cas++, A[2] + A[3]);
    }

    return 0;
}
