#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

struct splay_t {
  struct node {
    node *s[2];
    int size, key;
    int sum, lsum, rsum, msum;
    int cover_tag, reverse_tag;
    int rank() {
      return s[0]? 1+s[0]->size: 1;
    }
    node *set_cover(int _key) {
      cover_tag = 1;
      key = _key;
      sum = size*key;
      lsum = rsum = msum = max(sum, key);
      return this;
    }
    node *set_reverse() {
      reverse_tag ^= 1;
      swap(s[0], s[1]);
      swap(lsum, rsum);
      return this;
    }
    node *push() {
      for (int i = 0; i < 2; i++) {
        if (!s[i]) continue;
        if (cover_tag) s[i]->set_cover(key);
        if (reverse_tag) s[i]->set_reverse();
      }
      cover_tag = reverse_tag = 0;
      return this;
    }
    node *merge_sum(node *x, node *y) {
      if (!x || !y) return &(*this = x? *x: *y);
      sum = x->sum+y->sum;
      lsum = max(x->lsum, x->sum+y->lsum);
      rsum = max(y->rsum, x->rsum+y->sum);
      msum = max(x->msum, y->msum);
      msum = max(msum, max(lsum, rsum));
      msum = max(msum, x->rsum+y->lsum);
      return this;
    }
    node *pull() {
      size = 1;
      sum = lsum = rsum = msum = key;
      for (int i = 0; i < 2; i++) {
        if (!s[i]) continue;
        size += s[i]->size;
      }
      return merge_sum(node(*this).merge_sum(s[0], this), s[1]);
    }
    node *set(int b, node *x) {
      push()->s[b] = x;
      return pull();
    }
    node *get(int b) {
      return push()->s[b];
    }
    node *cut(int b, node *&x) {
      x = push()->s[b];
      s[b] = 0;
      return pull();
    }
  };
  node *give(node *t = 0) {
    static node *top = 0;
    static int size = 1;
    if (t) t->s[1] = top, top = t;
    else {
      if (!top) {
        top = new node[size<<=1];
        for (int i = 0; i < size-1; i++)
          top[i].s[1] = top+i+1;
        top[size-1].s[1] = 0;
      }
      t = top, top = top->s[1];
    }
    return t;
  }
  node *make(int key) {
    node t = {{0}, 1, key, key, key, key, key, 0, 0};
    return &(*give() = t);
  }
  void drop(node *&t) {
    if (!t) return ;
    drop(t->s[0]), drop(t->s[1]);
    give(t), t = 0;
  }
  void show(node *t) {
    if (!t) return ;
    t->push();
    show(t->s[0]);
    fprintf(stderr, " %d", t->key);
    show(t->s[1]);
    t->pull();
  }
	node *pick(node *t, int k) {
		node null = {{0}}, *x[2] = {&null, &null}, *y, *z;
		for ( ; ; ) {
			int r = t->rank(), b = k >= r;
			if (r == k) break;
			t->push();
			if (b) k -= r;
			int rr = t->s[b]->push()->rank(), bb = k >= rr;
			if (b == bb) {
				y = t->s[b];
				t->s[b] = y->s[!b];
				y->s[!b] = t->pull();
				t = y;
				if (rr == k) break;
				if (bb) k -= rr;
			}
			y = t->s[b];
			t->s[b] = x[!b];
			x[!b] = t;
			t = y;
		}
		t->push();
		for (int b = 0; b < 2; b++) {
			y = x[b]->s[!b];
			x[b]->s[!b] = t->s[b];
			for ( ; x[b] != &null; ) {
				z = y->s[!b];
				y->s[!b] = x[b]->pull();
				x[b] = y;
				y = z;
			}
			t->s[b] = null.s[!b];
		}
		return t->pull();
	}
	void merge(node *x, node *y, node *&t) {
		if (!x || !y) t = x? x: y;
		else t = pick(x, x->size)->set(1, y);
	}
	void split(node *t, int k, node *&x, node *&y) {
		if (!k) x = 0, y = t;
		else if (t->size == k) x = t, y = 0;
		else x = pick(t, k)->cut(1, y);
	}
	void slice(node *&t, int l = -1, int r = -1) {
		static node *a, *b;
		if (~l) split(t, l-1, a, b), split(b, r-l+1, t, b);
		else merge(t, b, b), merge(a, b, t);
	}
};
typedef splay_t::node node;

int get_int() {
  int x = 0, c = getchar(), b = 1;
  for ( ; isspace(c); ) c = getchar();
  if (c == '-') b = -1, c = getchar();
  for ( ; isdigit(c); c = getchar()) x = x*10+c-'0';
  return x*b;
}

splay_t zkl;
int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
		node *rt = 0;
    for (int i = 0; i < n; i++)
			zkl.merge(rt, zkl.make(get_int()), rt);
    for ( ; m--; ) {
      char op[20];
      scanf("%s", op);
      if (op[2] == 'X') {
				printf("%d\n", rt? rt->msum: 0);
      } else {
        int posi = get_int(), tot = get_int();
        if (*op == 'I') {
					node *x = 0;
					zkl.split(rt, posi, x, rt);
          for (int i = 0; i < tot; i++)
						zkl.merge(x, zkl.make(get_int()), x);
					zkl.merge(x, rt, rt);
        } else {
					zkl.slice(rt, posi, posi+tot-1);
          if (*op == 'D') {
						zkl.drop(rt);
          } else if (*op == 'M') {
						rt->set_cover(get_int());
          } else if (*op == 'R') {
						rt->set_reverse();
          } else if (*op == 'G') {
						printf("%d\n", rt? rt->sum: 0);
          }
					zkl.slice(rt);
        }
      }
    }
  }
  return 0;
}
