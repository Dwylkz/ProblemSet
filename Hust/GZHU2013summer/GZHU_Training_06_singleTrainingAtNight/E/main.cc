#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

double p, e[N][N];
int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%lf", &n, &p); ) {
    e[n][n] = 0.0;
    for (int i = n-1; 0 <= i; i--) e[i] = e[i+1]+1.0/p+1.0/(1.0-p);
    printf("%.1lf\n", e[0]);
  }
  return 0;
}
