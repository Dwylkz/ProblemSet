#pragma comment(linker,"/STACK:65536000,65536000")
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 1e6+5;
const int M = 1e9+7;

int Mul(int a, int b)
{
  return 1ll*a*b%M;
}

int Inverse(int a)
{
  int ret = 1, b = M-2;
  while (b) {
    if (b&1) ret = Mul(ret, a);
    a = Mul(a, a);
    b >>= 1;
  }
  return ret;
}

int n, bin[N], fac[N];
char b[N];

int Pure(int x)
{
  if (x == 0) return 1;
  return bin[x/2-1];
}

int Combine(int n, int m)
{
  return Mul(fac[n], Inverse(Mul(fac[n-m], fac[m])));
}

int main()
{
  bin[0] = 1;
  fac[0] = 1;
  for (int i = 1; i < N; i++) {
    if (i%2 == 0)
      bin[i] = Mul(bin[i-2], (i-2)/2+1);
    fac[i] = Mul(fac[i-1], i);
  }
  // for (int i = 0; i < 10; i++) printf("%d%c", bin[i], i < 9? ' ': '\n');
  while (~scanf("%d%s", &n, b)) {
    int nb = strlen(b), cnt = 0;
    for (int i = 0; b[i]; i++)
      if (b[i] == '(')
        cnt++;
      else
        cnt--;
    int m = n-nb, pure = m-cnt;
    if (cnt < 0 || n%2 == 1 || cnt > m || pure%2 == 1)
      puts("0");
    else
      printf("%d\n", Mul(bin[pure], Combine((m+1)/2, cnt)));
  }
  return 0;
}
