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
const int maxn = 2e3 + 10;

int n;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    vector<int> ans;
    for (int i = 1; i <= n * n / 2; i++) {
      ans.push_back(i);
      ans.push_back(1 + n * n - i);
      if (ans.size() == n) {
        for (int j = 0; j < n; j++) {
          printf("%d%c", ans[j], j < n - 1? ' ': '\n');
        }
        ans.clear();
      }
    }
  }
	return 0;
}
