//coder: SXDwylkz
//heads
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
	  output[] = "output.out";
const int inf32 = 0x7fffffff,
	  maxn = 1e5 + 10,
	  oo = -1;
const long long inf64 = 0x7fffffffffffffffLL; 

//type definition
typedef unsigned char UC;
typedef unsigned long long ULL;
typedef long long LL;
typedef int int_a[maxn];
typedef bool bool_a[maxn];
typedef char char_a[maxn];
typedef pair<int, int> II;

//simple fuction
LL dMin(LL lv, LL rv) {
	if (rv < lv) {
		swap(rv, lv);
	}
	if (lv == oo) {
		return rv;
	}
	return lv;
}
LL dMax(LL lv, LL rv) {
	if (rv < lv) {
		swap(rv, lv);
	}
	if (lv == oo) {
		return oo;
	}
	return rv;
}

//macro
#define WHERE	puts(__func__);
#define PA(H, A, I, S, E, F,...) {\
	puts(H);\
	for (int I = (S); I < (E); I++) {\
		printf(F,##__VA_ARGS__);\
	}\
	puts("");\
}

struct segment_node {
  segment_node *ls, *rs;
  int l, r,
      remain,
      use_tag,
      clean_tag;
  void set(int use, int clean)
  {
    if (clean) {
      remain = len();
      use_tag = 0;
      clean_tag = 1;
    }
    remain -= use;
    use_tag += use;
  }
  void push()
  {
    int d = min(ls->remain, use_tag);
    ls->set(d, clean_tag);
    rs->set(use_tag - d, clean_tag);
    use_tag = clean_tag = 0;
  }
  void update()
  {
    remain = ls->remain + rs->remain;
  }
  int len()
  {
    return r - l + 1;
  }
  int mid()
  {
    return l + r >> 1;
  }
  static const int pool_size = 1e6+10;
  static segment_node pool[pool_size], *pool_top;
  static void init()
  {
    pool_top = pool;
  }
  static segment_node *make()
  {
    return pool_top++;
  }
} segment_node::pool[], *segment_node::pool_top;
struct segment {
  segment_node *rt;
  void init(int l, int r)
  {
    build(rt = segment_node::make(), l, r);
  }
  void build(segment_node *x, int l, int r)
  {
    *x = (segment_node){0, 0, l, r, r - l + 1, 0, 0};
    if (l < r) {
      int m = l + r >> 1;
      build(x->ls = segment_node::make(), l, m);
      build(x->rs = segment_node::make(), m + 1, r);
    }
  }
  void cover(segment_node *x, int l, int r, int use, int clean)
  {
    if (l <= x->l && x->r <= r) {
      x->set(use, clean);
    } else {
      x->push();
      int m = x->mid(), d = 0;
      if (l <= m) {
        if (use) {
          d = min(ask_remain(x->ls, l, m), use);
        }
        cover(x->ls, l, r, d, clean);
      }
      if (m < r) {
        cover(x->rs, l, r, use - d, clean);
      }
      x->update();
    }
  }
  int ask_remain(segment_node *x, int l, int r)
  {
    int rv = 0;
    if (l <= x->l && x->r <= r) {
      rv = x->remain;
    } else {
      int m = x->mid();
      x->push();
      if (l <= m) {
        rv += ask_remain(x->ls, l, r);
      }
      if (m < r) {
        rv += ask_remain(x->rs, l, r);
      }
      x->update();
    }
    return rv;
  }
  int rank(segment_node *x, int l, int r, int i)
  {
    for ( ; l < r; ) {
      int m = l + r >> 1, j = ask_remain(rt, l, m);
      if (i <= j) {
        r = m;
      } else {
        l = m + 1;
        i -= j;
      }
    }
    return l;
  }
};

int n, m;
segment zkl;

//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
  int T;
	for (scanf("%d", &T); T--; ) {
    scanf("%d%d", &n, &m);
    segment_node::init();
    zkl.init(0, n - 1);
    for ( ; m--; ) {
      int k, x, y;
      scanf("%d%d%d", &k, &x, &y);
      if (k < 2) {
        y = min(y, zkl.ask_remain(zkl.rt, x, n - 1));
#if 0
        printf("(%d, %d), place %d\n", x, n - 1, y);
#endif
        if (y) {
          printf("%d %d\n",
              zkl.rank(zkl.rt, x, n - 1, 1),
              zkl.rank(zkl.rt, x, n - 1, y));
          zkl.cover(zkl.rt, x, n - 1, y, 0);
        } else {
          puts("Can not put any one.");
        }
      } else {
        printf("%d\n", (y - x + 1) - zkl.ask_remain(zkl.rt, x, y));
        zkl.cover(zkl.rt, x, y, 0, 1);
      }
    }
    puts("");
	}
	return 0;
}
