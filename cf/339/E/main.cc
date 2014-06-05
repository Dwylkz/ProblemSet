#include <map>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1e3+10;
typedef vector<int> vi_t;

int n, t[N], h[N], s[N];

bool dfs(int d) {
  int yes = 1;
  for (int i = 0; i < n; i++)
    if (t[i] != i) {
      yes = 0;
      break;
    }
  if (yes) {
    printf("%d\n", d);
    return 1;
  }
  if (d == 3) return 0;
  vi_t v;
  for (int i = 0; i < n; i++)
    if (s[t[i]]) v.push_back(i);
  for (int i = 0; i < v.size(); i++)
    for (int j = i+1; j < v.size(); j++) {
      reverse(t+v[i], t+v[j]+1);
      if (dfs(d+1)) {
        printf("%d %d\n", v[i]+1, v[j]+1);
        return 1;
      }
      reverse(t+v[i], t+v[j]+1);
    }
  return 0;
}

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) {
      scanf("%d", t+i);
      h[--t[i]] = i;
    }
    s[0] = s[n-1] = 1;
    for (int i = 0; i < n-1; i++)
      if (abs(h[i]-h[i+1]) > 1) s[i] = s[i+1] = 1;
    dfs(0);
  }
	return 0;
}
