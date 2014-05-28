#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e7+10;
const int M = 11;

char s[N];

int phi[M];
void init() {
  int p[] = {2, 3, 5, 7};
  for (int i = 1; i < M; i++) {
    phi[i] = i;
    for (int j = 0; j < 4; j++)
      if (i%p[j] == 0) phi[i] = phi[i]/p[j]*(p[j]-1);
  }
}
int hqmod(int a, int x, int c) {
  if (x >= phi[c]) x = x%phi[c]+phi[c];
  int rv = 1;
  for ( ; x; x >>= 1) {
    if (x&1) rv = rv*a%c;
    a = a*a%c;
  }
  return rv;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  init();
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    int c, b;
    scanf("%d%d%s", &c, &b, s);
    int l = strlen(s), rv = 0;
    for (int i = 0; i < l; i++)
      rv = (rv+(s[l-i-1]-'0')*hqmod(b, i, b-1))%(b-1);
    printf("%d %d\n", c, rv);
  }
  return 0;
}
