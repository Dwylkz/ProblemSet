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
    map<int, Node*> at;
    Node* f;
    char *k, *p;
  };

  struct Ref {
    Node* s;
    char *k, *p;

    CP(Node* s, char* k, char* p): s(s), k(k), p(p) {}

    bool Has(int c)
    {
      if (k == p) return (s->at.count(c) > 0);
      return (*p == c);
    }
  };

  static Node pool[N<<1];
  Node *root;
  Ref act;

  void Init()
  {
    top = pool;
    root = pool++;
    root->f = root->k = root->p = NULL;
    act = CP(root, NULL, NULL);
  }

  void Push(int c)
  {
    while (!act.Has(c)) {
    }
  }
};

int n;

int main()
{
  scanf("%d", &n);
  printf("%d", n);
  return 0;
}
