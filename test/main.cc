#include <iostream>
#include <vector>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <cstdarg>
using namespace std;

const int N = 1<<17;

struct Tree {
  int maxval_, delta_;

  void Add(int delta)
  {
    delta_ += delta;
    maxval_ += delta;
  }

  void Push(Tree& lval, Tree& rval)
  {
    lval.Add(delta_);
    rval.Add(delta_);
    delta_ = 0;
  }

  void Pull(Tree& lval, Tree& rval)
  {
    maxval_ = max(lval.maxval_, rval.maxval_);
  }
};

Tree tree[N*2+10];

void Add(int l, int r, int delta, int lb = 0, int rb = N, int x = 1)
{
  if (l <= lb && rb <= r) {
    tree[x].Add(delta);
    return ;
  }

  tree[x].Push(tree[x<<1], tree[x<<1|1]);

  int m = (lb+rb)>>1;
  if (l < m)
    Add(l, r, delta, lb, m, x<<1);
  if (m < r)
    Add(l, r, delta, m, rb, x<<1|1);

  tree[x].Pull(tree[x<<1], tree[x<<1|1]);
}

int Ask(int l, int r, int lb = 0, int rb = N, int x = 1)
{
  if (l <= lb && rb <= r)
    return tree[x].maxval_;

  tree[x].Push(tree[x<<1], tree[x<<1|1]);

  int m = (lb+rb)>>1, maxval = 0;
  if (l < m)
    maxval = max(maxval, Ask(l, r, lb, m, x<<1));
  if (m < r)
    maxval = max(maxval, Ask(l, r, m, rb, x<<1|1));

  tree[x].Pull(tree[x<<1], tree[x<<1|1]);
  return maxval;
}

int n, q;

int main()
{
  int* h = NULL;
  delete h;

  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    Add(i, i+1, ai);
  }

  while (q--) {
    int oper, l, r;
    scanf("%d%d%d", &oper, &l, &r);
    if (oper == 0) {
      int delta;
      scanf("%d", &delta);
      Add(l, r, delta);
    }
    else
      printf("%d\n", Ask(l, r));
  }
  return 0;
}
