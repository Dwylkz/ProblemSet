#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
const int maxn = 1e5 + 10;
typedef long long LL;

int n, a[maxn];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    int f = 0;
    for (int i = 31; 0 <= i; i--) {
      vector<int> b;
      int as = (1<<i)-1; 
      for (int j = 0; j < n; j++)
        if (a[j]&(1<<i)) {
          b.push_back(a[j]);
          as &= a[j];
        }
      if (!b.size()) continue;
      vector<int> c;
      for (int j = 0; j < b.size(); j++)
        if (!(as&b[j])) c.push_back(b[j]);
      if (!c.size()) continue;
      f = 1;
      printf("%d\n", c.size());
      for (int j = 0; j < c.size(); j++)
        printf("%d%c", c[j], j<c.size()-1? ' ': '\n');
      break;
    }
    if (!f) puts("-1");
  }
	return 0;
}
