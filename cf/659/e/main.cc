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

static const int N = 1e5+5;

struct E
{
  int v, next;
};
vector<E> e;
int h[N];

void Init()
{
  memset(h, -1, sizeof(h));
}

void Add(int u, int v)
{
  E t = {v, h[u]};
  h[u] = e.size();
  e.push_back(t);
}

void BAdd(int u, int v)
{
  Add(u, v);
  Add(v, u);
}

int n, m;
bool in[N];

int HasLoop(int u, int p)
{
  if (in[u] == true) return true;
  bool res = false;
  in[u] = true;
  for (int i = h[u]; i != -1; i = e[i].next)
  {
    if (e[i].v == p) continue;
    res |= HasLoop(e[i].v, u);
  }
  return res;
}

int main()
{
  Init();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    BAdd(x-1, y-1);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (in[i] == false)
    {
      if (!HasLoop(i, -1))
      {
        cnt++;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
