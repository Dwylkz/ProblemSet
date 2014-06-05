#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    int p[10];
    for (int i = 0; i < n; i++) p[i] = i;
    do {
      bool yes = 1, ca[10] = {0}, da[10] = {0}, aa[10] = {0}; 
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
          if (abs(p[i]-p[j]) == i-j) {
            yes = 0;
            break;
          }
        }
        if (!yes) break;
      }
      if (yes) {
        for (int i = 0; i < n; i++) printf("%d", p[i]+1);
        puts("");
      }
    } while(next_permutation(p, p+n));
  }
  return 0;
}
