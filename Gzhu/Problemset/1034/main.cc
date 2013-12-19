#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int MOD = 1e9+7;
const int N = 2;

struct Matrix {
  int d[N][N];
  int *operator [] (int x) { return d[x]; }
  friend Matrix &operator * (Matrix &lhs, Matrix &rhs) {
    static Matrix result;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        for (int k = result[i][j] = 0; k < N; k++)
          result[i][j] = (result[i][j]+1ll*lhs[i][k]*rhs[k][j])%MOD;
    return result;
  }
};

int n, k;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    Matrix a = {{n, 1, 0, 1}},
           b = {{0, 0, n, 0}},
           result = {{1, 0, 0, 1}};
    for ( ; k; k >>= 1, a = a*a)
      if (k&1) result = result*a;
    printf("%d\n", (result*b)[0][0]);
  }
  return 0;
}
