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

const int N = 8;

struct Vertex {
  int x, y;
  Vertex() {Vertex(0, 0);}
  Vertex(int x, int y): x(x), y(y) {}
  int Mod2()
  {
    return x*x+y*y;
  }
  friend Vertex operator - (const Vertex& lhs, const Vertex& rhs)
  {
    return Vertex(lhs.x-rhs.x, lhs.y-rhs.y);
  }
  friend int operator % (const Vertex& lhs, const Vertex& rhs)
  {
    return lhs.x*rhs.y-lhs.y*rhs.x;
  }
  friend int operator * (const Vertex& lhs, const Vertex& rhs)
  {
    return lhs.x*rhs.x+lhs.y*rhs.y;
  }
  void FromStdin()
  {
    scanf("%d%d", &x, &y);
  }
};

typedef vector<int> VI;
typedef vector<Vertex> VV;

Vertex v[N];

bool ForAll(bool is_valid(Vertex&, Vertex&, Vertex&), VV& ps)
{
  for (int i = 0; i < ps.size(); i++)
    if (!is_valid(ps[i], ps[(i+1)%ps.size()], ps[(i+2)%ps.size()]))
      return false;
  return true;
}

bool IsCounterClock(Vertex& p1, Vertex& p2, Vertex& p3)
{
  return (p2-p1)%(p3-p1) < 0;
}

bool IsOrthogonal(Vertex& p1, Vertex& p2, Vertex& p3)
{
  return (p2-p1)*(p3-p2) == 0;
}

bool IsRectangle(VV& ps)
{
  return ForAll(IsCounterClock, ps) && ForAll(IsOrthogonal, ps);
}

bool IsEqualEdge(VV& ps)
{
  return (ps[1]-ps[0]).Mod2() == (ps[2]-ps[1]).Mod2();
}

bool IsSquare(VV& ps)
{
  return IsRectangle(ps) && IsEqualEdge(ps);
}

bool IsValid(bool (*is_what)(VV&), VI& ps)
{
  do {
    VV vs;
    for (auto psi: ps)
      vs.push_back(v[psi]);
    if (is_what(vs))
      return true;
  } while (next_permutation(ps.begin(), ps.end()));
  return false;
}

int main()
{
  for (int i = 0; i < N; i++)
    v[i].FromStdin();
  for (int s = (1<<N)-1; ~s; s--) {
    VI ps[2];
    for (int i = 0; i < N; i++)
      ps[s>>i&1].push_back(i);
    if (ps[0].size() != ps[1].size())
      continue;
    if (IsValid(IsSquare, ps[0]) && IsValid(IsRectangle, ps[1])) {
      puts("YES");
      for (int i = 0; i < 4; i++)
        printf("%d%c", ps[0][i]+1, i < 3? ' ': '\n');
      for (int i = 0; i < 4; i++)
        printf("%d%c", ps[1][i]+1, i < 3? ' ': '\n');
      return 0;
    }
  }
  puts("NO");
  return 0;
}
