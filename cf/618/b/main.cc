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

const int N = 50+5;

int n, m[N][N], p[N];

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", m[i]+j);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (count(m[j], m[j]+n, i) == n-i)
        p[j] = i;
    }
  }
  *find(p, p+n, n-1) = n;
  for (int i = 0; i < n; i++) {
    printf("%d%c", p[i], i < n-1? ' ': '\n');
  }
  return 0;
}
