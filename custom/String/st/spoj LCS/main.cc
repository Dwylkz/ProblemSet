#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 5e5+5;

struct STree {
  struct Node {
    struct Pair {
      Pair(Node* s = NULL, int k = 0, int p = 0): s(s), k(k), p(p) {}
      Node* s;
      int k, p;
    };
    map<int, Pair> e;
    Node* f;
  };
  Node pool[N<<1], *rt, *top;
  vector<int> data;
  Node::Pair last;
  Node* New(Node* f)
  {
    top->e.clear();
    top->f = f;
    return top++;
  }
  void Init()
  {
    top = pool;
    rt = New(rt);
    last = Node::Pair(rt, 0, -1);
  }
  int End(int x)
  {
    return x < 0? data.size(): x;
  }
  bool Has(int c)
  {
    if (last.p < End(last.s->p)) return data[last.p] == c;
    return last.s->e.count(c) > 0;
  }
  Node* Add(int c, Node* f)
  {
    return NULL;
  }
  void Next(int c)
  {
  }
  void NextLink()
  {
  }
  void Push(int c)
  {
    data.push_back(c);
    Node* pre = NULL;
    while (!Has(c)) {
      pre = Add(c, pre);
      NextLink();
    }
    Next(c);
  }
};

STree zkl;
int n;
char foo[N];

int main()
{
  scanf("%s", foo);
  zkl.Init();
  for (int i = 0; foo[i]; i++)
    zkl.Push(foo[i]);
  return 0;
}
