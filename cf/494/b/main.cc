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

const int N = 1e5+5;
const int MOD = 1e9+7;

int Add(int a, int b)
{
  return (a+b)%MOD;
}

int n, p[N], f[N], g[N];
char s[N], t[N];

void Kmp(int* p, char* s)
{
  for (int i = 1, j = p[0] = -1; s[i]; i++) {
    while (j != -1 && s[j+1] != s[i])
      j = p[j];
    if (s[i] == s[j+1])
      j++;
    p[i] = j;
  }
}

int main()
{
  scanf("%s%s", s, t);
  Kmp(p, t);
  // for (int i = 0; t[i]; i++)
  //   printf(" %d", p[i]);
  // puts("");
  int j = -1, last = 0, nt = strlen(t);
  g[0] = 1;
  for (int i = 0; s[i]; i++) {
    if (i > 0)
      f[i] = Add(f[i-1], last);
    while (j != -1 && s[i] != t[j+1])
      j = p[j];
    if (s[i] == t[j+1])
      j++;
    if (!t[j+1])
      f[i] = Add(f[i], i-nt >= 0? g[i-nt]: 1);
    if (i > 0)
      g[i] = Add(g[i-1], 1+f[i]);
    if (!t[j+1]) {
      last = f[i];
      j = p[j];
      // printf("in %d\n", i);
    }
  }
  // for (int i = 0; s[i]; i++)
  //   printf("%d%c", f[i], !s[i+1]? '\n': ' ');
  // for (int i = 0; s[i]; i++)
  //   printf("%d%c", g[i], !s[i+1]? '\n': ' ');
  // printf("%d\n", f[strlen(s)-1]);
  return 0;
}
