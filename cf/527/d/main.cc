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

const int N = 2e5+5;

struct Fenwick
{
  static const int M = N<<1;
  int v[M];

  void Init()
  {
    memset(v, 0, sizeof(v));
  }

  void Add(int x, int y)
  {
    for (x++; x < M; x += -x&x) v[x] = max(v[x], y);
  }

  int Ask(int x)
  {
    int mv = 0;
    for (x++; x; x -= -x&x) mv = max(mv, v[x]);
    return mv;
  }
};

Fenwick ft;
int n;
pair<int, int> v[N];

int main()
{
  scanf("%d", &n);
  map<int, int> rank;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &v[i].first, &v[i].second);
    rank[v[i].first-v[i].second] = 0;
    rank[v[i].first+v[i].second] = 0;
  }
  int ranking = 0;
  for (auto& p: rank) p.second = ranking++;
  sort(v, v+n);
  ft.Init();
  for (int i = 0; i < n; i++) {
    int fid = rank[v[i].first-v[i].second];
    int uid = rank[v[i].first+v[i].second];
    ft.Add(uid, ft.Ask(fid)+1);
  }
  printf("%d\n", ft.Ask(ranking));
  return 0;
}
