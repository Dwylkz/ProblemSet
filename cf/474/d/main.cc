#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
const int M = 1e9+7;

int Add(int a, int b)
{
  return ((a+b)%M+M)%M;
}

int t, k, f[N];

int main()
{
  scanf("%d%d", &t, &k);
  f[0] = 1;

  for (int i = 1; i < N; i++) {
    f[i] = Add(f[i], f[i-1]);
    if (k <= i)
      f[i] = Add(f[i], f[i-k]);
  }

  for (int i = 1; i < N; i++)
    f[i] = Add(f[i], f[i-1]);

  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", Add(f[b], -f[a-1]));
  }
  return 0;
}
