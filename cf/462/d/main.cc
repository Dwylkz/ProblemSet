#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*  dp on tree.
 *
 *  define:
 *    tree(u):
 *      a tree with u as root
 *
 *    f(u, White):
 *      amount of ways to split the tree(u) into arbitray parts
 *      while part contains u has no black node and other part has exactly one black node.
 *
 *    f(u, Black):
 *      amount of ways to split the tree(u) into arbitray parts
 *      while each part has exactly one black node.
 *
 *  now we wanna merge tree(v) to tree(u), we have:
 *
 *    f(u, White)
 *      | size(u) == 1 = if x[u] == White then 1 else 0
 *      | x[u] == White = f(u, White)*f(v, White)+f(u, White)*f(v, Black)
 *      | x[u] == Black = 0
 *
 *    f(u, Black)
 *      | size(u) == 1 = if x[u] == Black then 1 else 0
 *      | x[u] == Black = f(u, Black)*(f(v, White)*f(v, Black))
 *      | x[u] == White = f(u, Black)*(f(v, White)*f(v, Black))+f(u, White)*f(v, Black)
 *
 *  finally, f(0, Black) is what we need.
 */

const int N = 1e5+10;
const int M = 1e9+7;

#define ADD(a, b) (((a)+(b))%M)
#define MUL(a, b) (1ll*(a)*(b)%M)

typedef vector<int> VI;

enum Color {
  W,
  B
};

int n, x[N], p[N], f[N][2];
VI g[N];

void Dfs(int u) {
  f[u][W] = (x[u] == W);
  f[u][B] = (x[u] == B);

  for (auto v: g[u]) {
    int t[2];
    memcpy(t, f[u], sizeof(t));

    Dfs(v);

    t[W] = (x[u] == W?
            ADD(MUL(f[u][W], f[v][W]), MUL(f[u][W], f[v][B])):
            0);

    t[B] = ADD(MUL(f[u][B], f[v][W]), MUL(f[u][B], f[v][B]));
    if (x[u] == W)
      t[B] = ADD(t[B], MUL(f[u][W], f[v][B]));

    memcpy(f[u], t, sizeof(t));
  }
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      g[i].clear();

    for (int i = 0; i < n-1; i++) {
      int u;
      cin >> u;

      int v = i+1;
      g[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
      cin >> x[i];

    Dfs(0);

    cout << f[0][B] << endl;
  }
  return 0;
}
