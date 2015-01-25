#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <stdint.h>

using namespace std;

const int N = 1e6+5;

typedef pair<int, int> R;
typedef vector<R> Rs;

int Gcd(int a, int b)
{
  if (b)
    return Gcd(b, a%b);
  return a;
}

R Trim(int x, int y)
{
  int gcd = Gcd(x, y);
  return R(x/gcd, y/gcd);
}

struct Trie {
  typedef map<R, Trie*> To;
  typedef To::iterator ToIter;

  Trie* f;
  To to;
  int c;
};
Trie trie[N], *top;
Trie* Make()
{
  top->f = NULL;
  top->to.clear();
  top->c = 0;
  return top++;
}
void Init()
{
  top = trie;
  Make();
}
void Push(Rs& rs)
{
  Trie* x = trie;
  for (int i = 0; i < (int)rs.size(); i++) {
    if (!x->to.count(rs[i]))
      x->to[rs[i]] = Make();
    x = x->to[rs[i]];
  }
  x->c++;
}
void Build()
{
  vector<Trie*> q;
  for (Trie::ToIter i = trie->to.begin(); i != trie->to.end(); i++) {
    q.push_back(i->second);
    i->second->f = trie;
  }
  for (int h = 0; h < (int)q.size(); h++)
    for (Trie::ToIter i = q[h]->to.begin(); i != q[h]->to.end(); i++) {
      q.push_back(i->second);
      Trie* y = q[h]->f;
      while (y->f != NULL && !y->to.count(i->first))
        y = y->f;
      if (y->to.count(i->first)) {
        i->second->f = y->to[i->first];
        i->second->c += i->second->f->c;
      } else {
        i->second->f = trie;
      }
    }
}
int64_t Eat(Rs& rs)
{
  int64_t res = 0ll;
  Trie* x = trie;
  int i = 0;
  while (i < (int)rs.size())
    if (x->to.count(rs[i])) {
      x = x->to[rs[i]];
      res += x->c;
      i++;
    } else if (x->f != NULL) {
      x = x->f;
    } else {
      i++;
    }
  return res;
}

int n, m;

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    Rs ask;
    int div = 0;
    for (int i = 0; i < n; i++) {
      int ai;
      scanf("%d", &ai);
      if (i > 0)
        ask.push_back(Trim(div, ai));
      div = ai;
    }
    Init();
    int64_t res = 0ll;
    for (int i = 0; i < m; i++) {
      int k;
      scanf("%d", &k);
      Rs rs;
      int div = 0;
      for (int j = 0; j < k; j++) {
        int bi;
        scanf("%d", &bi);
        if (j > 0)
          rs.push_back(Trim(div, bi));
        div = bi;
      }
      if (k == 1)
        res += n;
      else
        Push(rs);
    }
    Build();
    cout << res+Eat(ask) << endl;
  }
  return 0;
}
