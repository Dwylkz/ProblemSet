#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 16;
const int inf32 = 0x7fffffff;
typedef long long LL;

char s[maxn];
int power[1<<maxn]; // power[i] = log2(i)
int f[1<<maxn];
bool isp[1<<maxn];  // is palindrome

bool check(int ss)
{
  string t = "";
  for (int i = ss; i; i -= -i&i)
    t += s[power[-i&i]];
  for (int i = 0; i < t.length(); i++)
    if (t[i] != t[t.length() - i - 1])
      return 0;
#if 0
  printf("%s is palindrome\n", t.data());
#endif
  return 1;
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int i = 0; i < maxn; i++)
    power[1<<i] = i;
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%s", s);
    int l = strlen(s), bl = 1<<l;
    for (int i = 1; i < bl; i++) {
      isp[i] = check(i);
      f[i] = inf32;
    }
    for (int i = f[0] = 1; i < bl; i++)
      for (int j = i; j; j = (j-1) & i)
        if (isp[j] && (i&~j) == i-j && f[i]-1 > f[i&~j])
          f[i] = f[i&~j] + 1;
    printf("%d\n", f[bl-1]-1);
  }
  return 0;
}
