#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 4e3+10;
typedef long long LL;
typedef map<int, int> mll_t;
#define _i(x) x::iterator

mll_t cnt;
int a;
char s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &a); ) {
    scanf("%s", s);
    cnt.clear();
    int n = strlen(s), tot = 0;
    for (int i = 0; i < n; i++) s[i] -= '0';
    for (int i = 0; i < n; i++) {
      int t = 0;
      for (int j = i; j < n; j++) {
        tot++;
        t += s[j];
        cnt[t]++;
      }
    }
#if 0
    for (_i(mll_t) i = cnt.begin(); i != cnt.end(); i++)
      printf("%d->%d\n", i->first, i->second);
#endif
    LL result = 0;
    for (int i = 0; i < n; i++) {
      int t = 0;
      for (int j = i; j < n; j++) {
        t += s[j];
        if (!a) {
          if (!t) result += tot;
          else result += cnt[0];
        } else if (t && a%t == 0) result += cnt[a/t];
      }
    }
    cout << result << endl;
  }
  return 0;
}
