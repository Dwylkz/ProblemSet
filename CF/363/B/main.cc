#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 15e4+10;
const int inf = 1e9+10;

int n, k, s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    for (int i = 0; i < n; i++) scanf("%d", s+i);
    int id = 0, sum = 0;
    for (int i = 0; i < k; i++) sum += s[i];
    int mn = sum;
    for (int i = k; i < n; i++) {
      sum += s[i]-s[i-k];
      if (mn > sum) {
        id = i-k+1;
        mn = sum;
      }
    }
    printf("%d\n", id+1);
  }
  return 0;
}
