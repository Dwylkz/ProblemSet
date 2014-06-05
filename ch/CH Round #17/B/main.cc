#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+5;
const int mod = 1e9+7;

/* AC automaton
 * */
template<class T, int n, int m> struct aca_t {
  struct node {
    node *s[m], *p;
    int ac;
  } s[n], *top, *rt, *q[n];
  void init() {
    memset(top = s, 0, sizeof(s));
    rt = top++;
  }
  void put(T *k, int l, int ac) {
    node *x = rt;
    for (int i = 0; i < l; i++) {
      if (!x->s[k[i]]) x->s[k[i]] = top++;
      x = x->s[k[i]];
    }
    x->ac = ac;
  }
  void link() {
    int l = 0;
    for (int i = 0; i < m; i++)
      if (rt->s[i]) (q[l++] = rt->s[i])->p = rt;
      else rt->s[i] = rt;
    for (int h = 0; h < l; h++)
      for (int i = 0; i < m; i++)
        if (q[h]->s[i]) {
          (q[l++] = q[h]->s[i])->p = q[h]->p->s[i];
          q[h]->s[i]->ac |= q[h]->s[i]->p->ac;
        } else q[h]->s[i] = q[h]->p->s[i];
  }
  void tom(int mt[][n]) {
    for (node *x = s; x < top; x++)
      for (int i = 0; i < m; i++)
        if (!x->s[i]->ac) mt[x-s][x->s[i]-s] = 1;
  }
};
typedef aca_t<char, N*2, 2> aca_i;
typedef aca_i::node node;

aca_i zkl;
char buff[N];
int n, m, dp[N*2][N*2][N][1<<2];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    zkl.init();
    // 'D'
    buff[0] = 0;
    zkl.put(buff, 1, 0);
    // 'R'
    buff[0] = 1;
    zkl.put(buff, 1, 0);
    // 1st
    scanf("%s", buff);
    int buffl = strlen(buff);
    for (char *i = buff; *i; i++) *i = *i == 'R';
    zkl.put(buff, buffl, 1);
    // 2nd
    scanf("%s", buff);
    buffl = strlen(buff);
    for (char *i = buff; *i; i++) *i = *i == 'R';
    zkl.put(buff, buffl, 2);
    zkl.link();
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for (int i = 0; i < n+m; i++)
      for (node *u = zkl.rt; u < zkl.top; u++) {
        int x = u-zkl.rt;
        for (int k = 0; k < 2; k++) {
          int y = u->s[k]-zkl.rt;
          for (int j = 0; j <= m; j++)
            for (int s = (1<<2)-1; ~s; s--)
              (dp[i+1][y][j+k][s|u->s[k]->ac] += dp[i][x][j][s]) %= mod;
        }
      }
    int result = 0;
    for (node *u = zkl.rt; u < zkl.top; u++)
      (result += dp[n+m][u-zkl.rt][m][3]) %= mod;
    printf("%d\n", result);
  }
  return 0;
}
