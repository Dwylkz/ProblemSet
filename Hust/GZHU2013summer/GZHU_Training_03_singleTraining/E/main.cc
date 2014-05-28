#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

int n, m;
int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  while (~scanf("%d%d", &n, &m)) {
    while (n != m) {
      if (n > m) n >>= 1;
      else m >>= 1;
    }
    printf("%d\n", n);
  }
  return 0;
}
