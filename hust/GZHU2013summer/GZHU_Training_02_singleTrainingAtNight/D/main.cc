#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e4 + 10;
typedef long long LL;

int n, m, w[maxn], f[maxn];

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
	for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", w+i);
    scanf("%d", &m);
    memset(f, 0, sizeof(f));
    f[0] = 1;
    sort(w, w+n);
    for (int i = 0; i < n; i++)
      for (int j = maxn - 1; 0 <= j; j--)
        if (m-(j-w[i]) >= 5 && f[j-w[i]]) f[j] = 1;
    for (int i = maxn - 1; 0 <= i; i--)
      if (f[i]) {
        printf("%d\n", m-i);
        break;
      }
	}
	return 0;
}
