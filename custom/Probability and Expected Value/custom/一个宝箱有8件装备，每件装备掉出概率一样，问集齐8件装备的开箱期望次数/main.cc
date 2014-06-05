#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 8;
const int S = 1<<N;

/* |s| < |S|: f[s] = (f[s]+1)*|s|/N+(f[s-{i}]+1)*1/N, i in s;
 *            f[s] = |s|/(N-|s|)+f[s-{i}]+1
 * |s| == |S|: f[s] = (f[s-{i}]+1)*1/N, i in s;
 * */
double f[S];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  f[S] = 1.0;
  for (int s = 1; s < S; s++) {
    f[s] = 0.0;
    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += s>>i&1;
    for (int i = 0; i < N; i++)
      if (s>>i&1) f[s] += f[s^(1<<i)]+1;
    if (s < S-1) f[s] = (cnt+f[s])/(N-cnt);
    else f[s] /= N;
  }
  printf("%lf\n", f[S-1]);
  return 0;
}
