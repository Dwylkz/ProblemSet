#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int K = 2e2+10;
const int N = 25e1+10;

int x, k, p;

double f[K][N][N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> x >> k >> p) {
    int o = 0, z = 0;
    while (x && x%2 == 0) {
      x /= 2;
      z++;
    }
    while (x%2 == 1) {
      x /= 2;
      o++;
    }
    memset(f, 0, sizeof(f));
    f[0][o][z] = 1.0;
    double p1 = 1.0*p/100.0, p2 = 1.0-p1;
    for (int i = 0; i < k; i++)
      for (int oi = 0; oi < N; oi++)
        for (int zi = 0; zi < N; zi++) {
          if (zi+1 < N)
            f[i+1][oi][zi+1] += f[i][oi][zi]*p1;
          if (zi+oi < N)
            f[i+1][1][zi+oi] += f[i][oi][zi]*p2;
        }

    double res = 0.0;
    for (int oi = 0; oi < N; oi++)
      for (int zi = 0; zi < N; zi++)
        res += f[k][oi][zi]*zi;

    cout << res << endl;

  }
  return 0;
}
