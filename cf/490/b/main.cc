#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 2e6+10;

typedef map<int, int> MII;

int n, q[N];
bool used[N];
MII l, r;

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    l[bi] = ai;
    r[ai] = bi;
  }
  for (int i = 1, c = 0; r.count(c) && r[c]; i += 2) {
    q[i] = r[c];
    c = r[c];
    used[c] = true;
  }
  if (n%2 == 0) {
    for (int i = n-2, c = 0; l.count(c); i -= 2) {
      q[i] = l[c];
      c = l[c];
    }
  }
  else {
    int c;
    for (auto& i: l)
      if (i.first && !used[i.first])
        c = i.first;
      else if (i.second && !used[i.second])
        c = i.second;
    while (l.count(c))
      c = l[c];
    q[0] = c;
    for (int i = 2; r.count(c); i += 2) {
      q[i] = r[c];
      c = r[c];
    }
  }
  for (int i = 0; i < n; i++)
    printf("%d%c", q[i], i < n-1? ' ': '\n');
  return 0;
}
