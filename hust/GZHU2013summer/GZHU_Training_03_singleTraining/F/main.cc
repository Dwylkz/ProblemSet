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
  for ( ; ~scanf("%d%d", &n, &m); ) {
    string t = "";
    for ( ; m; m /= n) t += m%n + '0';
    for (int i = 0; i < t.length()/2; i++)
      swap(t[i], t[t.length()-i-1]);
    printf("%s\n", t.data());
  }
  return 0;
}
