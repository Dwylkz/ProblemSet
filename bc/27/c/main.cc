#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <stdint.h>

using namespace std;

const int N = 3e5+5;

int n, m, a[N], b[N];

bool Equal(int x[], int i, int y[], int j)
{
  return x[i-1]*y[j] == x[i]*y[j-1];
}

int p[N];
void Kmp(int s[], int n)
{
  p[0] = -1;
  int i = 1, j = -1;
  while (i < n)
    if (Equal(s, j+1, s, i)) {
      p[i] = j+1;
      i++;
      j++;
    } else if (j == -1) {
      p[i] = -1;
      i++;
    } else {
      j = p[j];
    }
}
int Kmp(int x[], int n, int y[], int m)
{
  int i = 0, j = -1, res = 0;
  while (i < n)
    if (Equal(x, i, y, j+1)) {
      i++;
      j++;
      if (j+1 == m) {
        res++;
        j = p[j];
      }
    } else if (j == -1) {
      i++;
    } else {
      j = p[j];
    }
  return res;
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    int64_t res = 0;
    for (int i = 0; i < m; i++) {
      int k;
      scanf("%d", &k);
      for (int j = 0; j < k; j++)
        scanf("%d", b+j);
      if (k == 1) {
        res += n;
        continue;
      }
      Kmp(b+1, k-1);
      res += Kmp(a+1, n-1, b+1, k-1);
    }
    cout << res << endl;
  }
  return 0;
}
