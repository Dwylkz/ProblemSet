#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

int n;
char p[N], s[N];

void plus1() {
  int l = strlen(p);
  reverse(p, p+l);
  for (int i = 0; i < l; i++) p[i] -= '0';
  p[0]++;
  for (int i = 0; i < l; i++) {
    p[i+1] += p[i]/10;
    p[i] %= 10;
  }
  if (p[l]) p[++l] = 0;
  for (int i = 0; i < l; i++) p[i] += '0';
  reverse(p, p+l);
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    scanf("%d%s", &n, p);
    int id = 0;
    for (int i = 1; i < n; i++) {
      scanf("%s", s);
      plus1();
#if 0
      printf("%s == %s?\n", p, s);
#endif
      if (!id && strcmp(p, s)) id = i+1;
      strcpy(s, p);
    }
    if (!id) id = 1;
    printf("Case #%d: %d\n", ks, id);
  }
  return 0;
}
