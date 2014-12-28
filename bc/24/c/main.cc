#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 5e4+5;
const int M = 2333333;

int Add(int a, int b)
{
  return ((a+b)%M+M)%M;
}

int Mul(int a, int b)
{
  return 1ll*a*b%M;
}

int QM(int a, int b)
{
  int ret = 1;
  while (b > 0) {
    if (b&1)
      ret = Mul(ret, a);
    a = Mul(a, a);
    b >>= 1;
  }
  return ret;
}

struct Node {
  int sum, det, l, r, m;
  Node *ls, *rs;

  Node()
  {
  }

  Node(int sum, int det, int l, int r, int m):
      sum(sum), det(det), l(l), r(r), m(m)
  {
  }

  void Set(int det_)
  {
    det = Add(det, det_);
    sum = Add(sum, Mul(r-l+1, det_));
  }

  void Push()
  {
    ls->Set(det);
    rs->Set(det);
    det = 0;
  }

  void Pull()
  {
    sum = Add(ls->sum, rs->sum);
  }
};

Node tree[N<<1], *top;

Node* Build(int* a, int l, int r)
{
  Node* x = top++;
  *x = Node(0, 0, l, r, (l+r)>>1);
  if (l == r) {
    x->sum = a[l];
    return x;
  }
  x->ls = Build(a, l, x->m);
  x->rs = Build(a, x->m+1, r);
  x->Pull();
  return x;
}

Node* Init(int* a, int l, int r)
{
  top = tree;
  return Build(a, l, r);
}

void Add(Node* x, int l, int r, int det)
{
  if (l <= x->l && x->r <= r) {
    x->Set(det);
    return ;
  }
  x->Push();
  if (l <= x->m)
    Add(x->ls, l, r, det);
  if (x->m < r)
    Add(x->rs, l, r, det);
  x->Pull();
}

int Ask(Node* x, int l, int r)
{
  if (l <= x->l && x->r <= r)
    return x->sum;
  int sum = 0;
  x->Push();
  if (l <= x->m)
    sum = Add(sum, Ask(x->ls, l, r));
  if (x->m < r)
    sum = Add(sum, Ask(x->rs, l, r));
  x->Pull();
  return sum;
}

int n, m, a[N];

int main()
{
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    Node* root = Init(a, 0, n-1);
    // printf("use %ld\n", top-root);
    while (m--) {
      int t, x, y, z;
      scanf("%d", &t);
      // printf("%d\n", t);
      if (t == 1) {
        scanf("%d%d", &x, &y);
        printf("%d\n", Ask(root, x-1, y-1));
      } else if (t == 2) {
        scanf("%d", &x);
        x--;
        int ax = Ask(root, x, x);
        Add(root, x, x, -ax);
        Add(root, x, x, QM(2, ax));
      } else if (t == 3) {
        scanf("%d%d%d", &x, &y, &z);
        Add(root, x-1, y-1, z);
      }
    }
  }
  return 0;
}
