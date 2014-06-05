#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 2e3+10;

int n, to[N];
vector<int> p[N];
LL r;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%lld", &n, &r); ) {
    for (int i = 0; i < n; i++) {
      scanf("%d", to+i);
      to[i]--;
    }
    for (int i = 0; i < n; i++) {
      int head = i, now = i;
      p[i].clear();
      p[i].push_back(now);
      for (now = to[now]; now != head; now = to[now])
        p[i].push_back(now);
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", p[i][r%p[i].size()]+1, i < n-1? ' ': '\n');
  }
  return 0;
}
