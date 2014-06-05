#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
using namespace std;
const int N = 1e2+10;
typedef bitset<N> bs_t;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    vector<bs_t> a(n);
    for (int i = 0; i < n; i++) {
      int m;
      scanf("%d", &m);
      for (int j = 0; j < m; j++) {
        int ai;
        scanf("%d", &ai);
        a[i].set(ai);
      }
    }
    for (int i = 0; i < n; i++) {
      bool yes = 1;
      for (int j = 0; j < n; j++)
        if (i != j) {
          for (int k = 0; k < N; k++)
            if ((a[j]|a[i]) == a[i] && a[i].count() >= a[j].count())
              yes = 0;
        }
      puts(yes? "YES": "NO");
    }
  }
  return 0;
}
