#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;
const int M = 26;

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
typedef aca_t<char, N, M> aca_i;
typedef aca_i::node node;

aca_i zkl;
int n, m;
double p[M], dp[N][N];
char buff[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m), n|m; ) {
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; i++) {
      double pi;
      scanf("%1s%lf", buff, &pi);
      p[*buff-'a'] = pi;
    }
    scanf("%s", buff);
    int l = strlen(buff);
    zkl.init();
    for (int i = 0; i < l; i++) buff[i] -= 'a';
    zkl.put(buff, l, 1);
    for (int i = 0; i < M; i++) {
      buff[0] = i;
      zkl.put(buff, 1, 0);
    }
    zkl.link();
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1.;
    double result = 0.;
    for (int i = 0; i < m; i++) {
      for (node *j = zkl.s; j < zkl.top; j++) {
        int x = j-zkl.s;
        for (int k = 0; k < M; k++) {
          int y = j->s[k]-zkl.s;
          if (j->s[k]->ac) continue;
          dp[y][i+1] += dp[x][i]*p[k];
        }
      }
    }
    for (node *i = zkl.s; i < zkl.top; i++)
      result += dp[i-zkl.s][m];
    printf("%.2f%%\n", (1.-result)*100.);
  }
  return 0;
}
