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

int n, p[N], f[N], fs[N], fss[N];
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
  int j = -1, nt = strlen(t);
  for (int i = 0; s[i]; i++) {
    while (j != -1 && t[j+1] != s[i])
      j = p[j];
    if (t[j+1] == s[i])
      j++;
    if (!t[j+1]) {
      f[i+1] = Add(fss[i-nt+1], (i+1)-nt+1);
      j = p[j];
    }
    else {
      f[i+1] = f[i];
    }
    fs[i+1] = Add(fs[i], f[i+1]);
    fss[i+1] = Add(fss[i], fs[i+1]);
  }
  printf("%d\n", fs[strlen(s)]);
  return 0;
}
