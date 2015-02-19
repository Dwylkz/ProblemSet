#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 1e2+5;

int GCD(int a, int b)
{
  if (b > 0) {
    return GCD(b, a%b);
  }
  return a;
}

int n, m;
bool b[N], g[N];

int main()
{
  scanf("%d%d", &n, &m);
  int nb;
  scanf("%d", &nb);
  for (int i = 0; i < nb; i++) {
    int bi;
    scanf("%d", &bi);
    b[bi] = true;
  }
  int ng;
  scanf("%d", &ng);
  for (int i = 0; i < ng; i++) {
    int gi;
    scanf("%d", &gi);
    g[gi] = true;
  }
  int lcm = (n+m)*n*m;
  for (int i = 0; i < lcm; i++) {
    int bi = i%n;
    int gi = i%m;
    bool h = b[bi]|g[gi];
    b[bi] = h;
    g[gi] = h;
  }
  // for (int i = 0; i < n; i++) {
  //   printf("%d%c", b[i], (i < n-1? ' ': '\n'));
  // }
  // for (int i = 0; i < m; i++) {
  //   printf("%d%c", g[i], (i < m-1? ' ': '\n'));
  // }
  if (count(b, b+n, false)+count(g, g+m, false) == 0) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}
