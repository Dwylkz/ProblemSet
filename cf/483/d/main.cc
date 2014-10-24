#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int M = 1e5+5;
const int B = 30;

struct Node {
  char sum;

  void Set()
  {
    sum = 1;
  }

  void Push(Node& ls, Node& rs)
  {
    if (sum != 1)
      return ;

    ls.Set();
    rs.Set();
  }

  void Pull(Node& ls, Node &rs)
  {
    sum = ls.sum&rs.sum;
  }
};

struct Tree {
  static const int N = 1<<17;

  Node data[N*2+5];

  int Ls(int x) {return x<<1;}

  int Rs(int x) {return x<<1|1;}

  void Add(int l, int r, int lb = 0, int rb = N, int x = 1)
  {
    if (l <= lb && rb <= r) {
      data[x].Set();
      return ;
    }

    data[x].Push(data[Ls(x)], data[Rs(x)]);
    int m = (lb+rb)/2;
    if (l < m)
      Add(l, r, lb, m, Ls(x));
    if (m < r)
      Add(l, r, m, rb, Rs(x));
    data[x].Pull(data[Ls(x)], data[Rs(x)]);
  }

  int Ask(int l, int r, int lb = 0, int rb = N, int x = 1)
  {
    if (l <= lb && rb <= r) {
      return data[x].sum;
    }

    data[x].Push(data[Ls(x)], data[Rs(x)]);
    int m = (lb+rb)/2, ret = 1;
    if (l < m)
      ret &= Ask(l, r, lb, m, Ls(x));
    if (m < r)
      ret &= Ask(l, r, m, rb, Rs(x));
    data[x].Pull(data[Ls(x)], data[Rs(x)]);
    return ret;
  }
};

struct Ask {
  int l, r, q;

  void Read()
  {
    scanf("%d%d%d", &l, &r, &q);
  }
};

Tree tree[B];
Ask ask[M];
int n, m;

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    ask[i].Read();
    for (int j = 0; j < B; j++)
      if (ask[i].q>>j&1)
        tree[j].Add(ask[i].l-1, ask[i].r);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < B; j++)
      if (~ask[i].q>>j&1)
        if (tree[j].Ask(ask[i].l-1, ask[i].r)) {
          puts("NO");
          return 0;
        }
  }

  puts("YES");
  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = 0; j < B; j++)
      x |= tree[j].Ask(i, i+1)<<j;
    printf("%d%c", x, i < n-1? ' ': '\n');
  }
  return 0;
}
