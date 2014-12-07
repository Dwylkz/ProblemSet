#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 1<<17;

typedef long long LL;
typedef map<LL, int> MII;

struct Info {
  int s, l, a;
  friend istream& operator >> (istream& lhs, Info& rhs)
  {
    lhs >> rhs.s >> rhs.l >> rhs.a;
    return lhs;
  }
  friend bool operator < (const Info& lhs, const Info& rhs)
  {
    return lhs.l < rhs.l;
  }
};

struct Node {
  LL s;
  Node* to[2];
};
Node pst[N*19], *top, *root[N];
Node* Phi(int l, int r)
{
  Node* x = top++;
  x->s = 0;
  if (l == r)
    return x;
  int m = (l+r)/2;
  x->to[0] = Phi(l, m);
  x->to[1] = Phi(m+1, r);
  return x;
}
Node* Add(int i, int d, int lb, int rb, Node* p)
{
  Node *x = top++;
  *x = *p;
  x->s += d;
  if (lb == rb)
    return x;
  int m = (lb+rb)/2;
  if (i <= m)
    x->to[0] = Add(i, d, lb, m, p->to[0]);
  else
    x->to[1] = Add(i, d, m+1, rb, p->to[1]);
  return x;
}
LL Ask(int l, int r, int lb, int rb, Node* x, Node* y)
{
  if (l <= lb && rb <= r)
    return y->s-x->s;
  LL ans = 0;
  int m = (lb+rb)/2;
  if (l <= m)
    ans += Ask(l, r, lb, m, x->to[0], y->to[0]);
  if (m < r)
    ans += Ask(l, r, m+1, rb, x->to[1], y->to[1]);
  return ans;
}

Info a[N];
int n;

int Lower(MII& m, LL v)
{
  MII::iterator i = m.lower_bound(v);
  return i == m.end()? m.size(): i->second;
}
int Upper(MII& m, LL v)
{
  MII::iterator i = m.upper_bound(v);
  return i == m.end()? m.size(): i->second;
}

int main()
{
  ios_base::sync_with_stdio(false);
  while (cin >> n) {
    MII dl, da;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      dl[a[i].l] = 0;
      da[a[i].a] = 0;
    }
    int idx = 0;
    for (MII::iterator i = dl.begin(); i != dl.end(); i++)
      i->second = idx++;
    idx = 0;
    for (MII::iterator i = da.begin(); i != da.end(); i++)
      i->second = idx++;
    sort(a, a+n);
    top = pst;
    root[0] = Phi(0, da.size()-1);
    Node* last = root[0];
    for (int i = 0; i < n; i++) {
      root[dl[a[i].l]+1] = Add(da[a[i].a], a[i].s, 0, da.size()-1, last);
      last = root[dl[a[i].l]+1];
    }
    int q;
    cin >> q;
    LL k = 0;
    while (q--) {
      LL ll, hl, la, ha;
      cin >> ll >> hl >> la >> ha;
      ll += k;
      hl -= k;
      la += k;
      ha -= k;
      if (ll > hl)
        swap(ll, hl);
      if (la > ha)
        swap(la, ha);
      int llb = Lower(dl, ll), lrb = Upper(dl, hl);
      int alb = Lower(da, la), arb = Upper(da, ha);
      if (llb == lrb || alb == arb) {
        k = 0;
        cout << k << endl;
        continue;
      }
      // cout << llb << ' ' << lrb << ' ' << alb << ' '  << arb << endl;
      k = Ask(alb, arb-1, 0, da.size()-1, root[llb], root[lrb]);
      cout << k << endl;
    }
  }
  return 0;
}
