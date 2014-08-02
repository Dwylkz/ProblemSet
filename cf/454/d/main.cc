#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef vector<int> VI;

/* Lemma:
 *  forall b[i] in [1, 2*mx) where mx = max(a)
 * Prove:
 *  Provided there is a solution that obey sum(abs(ai-bi)) is minimum
 *  and exists b[k] in [2*mx, oo).
 *  
 *  Since we could puts 1s into b arbitrarily (as the gcd(1, ?) = 1)
 *  and a[k] in [1, mx].
 *  We have (b[k]-a[k]) in [mx, oo) while (1-a[k]) in [0, mx) if we replace b[k] with 1.
 *
 *  As abs(1-a[k]) < abs(b[k]-a[k]), so there is another solution smaller.
 *  The contradiction appeared.
 * */
const int N = 1e2+10;
const int P = 60;
const int M = 17;
const int S = 1<<M;

VI ps;
int fac[P];
bool IsPrime(int x)
{
  for (int i = 2; i*i <= x; i++)
    if (x%i == 0)
      return false;
  return true;
}
void Gen()
{
  for (int i = 2; i < P; i++)
    if (IsPrime(i))
      ps.push_back(i);

  for (int i = 1; i < P; i++)
    for (int j = 0; j < ps.size(); j++)
      if (i%ps[j] == 0)
        fac[i] |= 1<<j;
}

int n, a[N];

int f[N][S], g[N][S];
void Show(int x, int y)
{
  if (x > 1)
    Show(x-1, y&~fac[g[x][y]]);

  printf("%d%c", g[x][y], x == n? '\n': ' ');
}

int main()
{
  cin.sync_with_stdio(0);
  Gen();
  for ( ;cin >> n; ) {
    for (int i = 0; i < n; i++)
      cin >> a[i];

    memset(f, 0x3f, sizeof(f));
    memset(g, -1, sizeof(g));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < P; j++) {
        int mask = (S-1)&~fac[j];
        for (int s = mask; ; s = (s-1)&mask) {
          int to = s|fac[j];
          int val = f[i-1][s]+abs(j-a[i-1]);
          if (f[i][to] > val) {
            f[i][to] = val;
            g[i][to] = j;
          }

          if (s == 0)
            break;
        }
      }
    }

    int id = 0;
    for (int i = 0; i < S; i++)
      if (f[n][i] < f[n][id])
        id = i;

    Show(n, id);
  }
  return 0;
}
