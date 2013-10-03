#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <bitset>
#include <vector>
#include <map>
using namespace std;
const int N = 1<<17;
const int M = 15+10;
const int B = 1024+10;
typedef map<int, int> mii_t;
#define _i(t) t::iterator
typedef bitset<B> bs_t;
typedef vector<bs_t> vbs_t;
typedef pair<int, int> pii_t;
#define _l first
#define _r second

bool cmp(const pii_t &lhs, const pii_t &rhs) {
  return lhs._l == rhs._l? lhs._r < rhs._r: lhs._l < rhs._l;
}
struct oper_t {
  int op, id, m;
  vector<pii_t> s;
  void show() {
    printf("op=%c, id=%d, m=%d\n", op, id ,m);
    for (int i = 0; i < m; i++)
      printf("\t%d %d\n", s[i]._l, s[i]._r);
  }
  oper_t &input(int _op) {
    op = _op;
    if (op == 'E') {
      scanf("%d%d", &id, &m);
      s.resize(m);
      for (int i = 0; i < m; i++)
        scanf("%d%d", &s[i]._l, &s[i]._r);
    } else if (op == 'D') {
      scanf("%d", &id);
      m = 0;
    } else {
      s.resize(m = 1);
      scanf("%d%d", &s[0]._l, &s[0]._r);
    }
    return *this;
  }
  void join() {
    sort(s.begin(), s.end(), cmp);
    for (int i = m-1; i; i--)
      if (s[i]._l-s[i-1]._r < 2) {
        s[i-1]._r = max(s[i-1]._r, s[i]._r);
        m--;
      }
  }
};

struct bia_t {
  vbs_t s;
  void init(int n) {
    s = vbs_t(n+10, bs_t(0));
  }
  void add(int x, int id, int bit) {
    for (x++; x < s.size(); x += -x&x) s[x][id] = bit;
  }
  bs_t ask(int x) {
    bs_t result(0);
    for (x++; x; x -= -x&x) result ^= s[x];
    return result;
  }
};

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  vector<oper_t> o;
  mii_t disc;
  for (char op[10]; ~scanf("%1s", op); ) {
    o.push_back(oper_t());
    o.back().input(*op);
    if (*op != 'D') {
      for (int i = 0; i < o.back().m; i++)
        disc[o.back().s[i]._l] = disc[o.back().s[i]._r] = 1;
      o.back().join();
    }
  }
  int rank = 1;
  for (_i(mii_t) i = disc.begin(); i != disc.end(); i++)
    i->second = rank++;
  bia_t zkl;
  zkl.init(disc.size()<<1);
  int pre[B];
  for (int op = 0; op < o.size(); op++)
    if (o[op].op != 'F') {
      int id = op, bit = 1;
      if (o[op].op == 'E') {
        pre[o[op].id] = op;
      } else {
        id = pre[o[op].id];
        bit = 0;
      }
      for (int i = 0; i < o[id].m; i++) {
        int l = disc[o[id].s[i]._l]<<1,
            r = disc[o[id].s[i]._r]<<1|1;
        zkl.add(l, o[id].id, bit);
        zkl.add(r, o[id].id, bit);
      }
    } else {
      int l = disc[o[op].s[0]._l]<<1,
          r = disc[o[op].s[0]._r]<<1;
      puts((zkl.ask(l)&zkl.ask(r)).any()? "F": "D");
    }
  return 0;
}
