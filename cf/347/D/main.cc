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

const int N = 1e2+5;

struct Dp {
  int p, w;
  friend bool operator < (const Dp& lhs, const Dp& rhs) {
    return lhs.w > rhs.w;
  }
};

int n, p[N];
char a[N], b[N], v[N];

void Kmp(int* p, char* s)
{
  for (int i = 1, j = p[0] = -1; s[i]; i++) {
    while (~j && s[j+1] != s[i])
      j = p[j];
    if (s[j+1] == s[i])
      j++;
    p[i] = j;
  }
}

int main()
{
  scanf("%s%s%s", a, b, v);
  Kmp(p, v);
  int nv = strlen(v);
  for (int i = 0; a[i]; i++)
    for (int j = 0; b[j]; j++)
      for (int k = 0; k <= nv; k++) {
      }
  printf("%d", n);
  return 0;
}
