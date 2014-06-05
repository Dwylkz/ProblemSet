#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
typedef long long LL;
const int maxn = 1e5 + 10;

struct order {
  int a, b, id, id2;
  friend bool operator < (order x, order y) {
    if (x.a != y.a) {
      return x.a < y.a;
    }
    return x.b < y.b;
  }
} o[maxn];
bool cmp(order x, order y) {
  if (x.b != y.b) {
    return x.b > y.b;
  }
  return x.a > y.a;
}
int n, p, k;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &p, &k); ) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &o[i].a, &o[i].b);
      o[i].id = i + 1;
    }
    sort(o, o + n, cmp);
#if 0
    for (int i = 0; i < n; i++) {
      printf("%d %d %d\n", o[i].a, o[i].b, o[i].id);
    }
#endif
    for (int i = 0; i < n; i++) {
      o[i].id2 = i;
    }
    priority_queue<order> Q;
    for (int i = 0; i < n - (p - k); i++) {
      Q.push(o[i]);
    }
    vector<int> ans;
    ans.clear();
    int mid = -1;
    for (int i = 0; i < k; i++) {
      ans.push_back(Q.top().id);
      mid = max(mid, Q.top().id2);
      Q.pop();
    }
    for (int i = 0; i < p - k; i++) {
      ans.push_back(o[i + mid + 1].id);
    }
    for (int i = 0; i < ans.size(); i++) {
      printf("%d%c", ans[i], (i < ans.size() - 1? ' ': '\n'));
    }
  }
	return 0;
}
