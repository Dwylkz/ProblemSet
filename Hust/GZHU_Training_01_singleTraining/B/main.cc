#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 10;
typedef long long LL;

int n;
double p[maxn];

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
	for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++)
      scanf("%lf", p+i);
    sort(p, p + n);
    double sum = 0;
    for (int i = 1; i < n - 1; i++)
      sum += p[i];
    printf("%.2lf\n", sum/(n-2.0));
	}
	return 0;
}
