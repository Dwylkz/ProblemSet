#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 1e3+10;
typedef map<string, int> msi_t;
#define _i(t) t::iterator

char name[N][N];
int n, d[N];

int main() {
#if 0
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    printf("Case #%d: ", ks);
    scanf("%d", &n);
    getchar();
    msi_t m;
    for (int i = 0; i < n; i++) {
      gets(name[i]);
      m[name[i]] = 1;
    }
    int r = 0;
    for (_i(msi_t) i = m.begin(); i != m.end(); i++) i->second = r++;
    for (int i = 0; i < n; i++) d[i] = m[name[i]];
    int rv = 0;
    for (int i = 1; i < n; i++)
      if (d[i] < d[i-1]) {
        for ( ; i && d[i] < d[i-1]; i--)
          swap(d[i], d[i-1]);
        rv++;
        i++;
      }
    printf("%d\n", rv);
  }
  return 0;
}
