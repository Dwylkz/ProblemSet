#pragma comment(linker,"/STACK:65536000,65536000")
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 5e4+5;
const LL oo = (-1ull<<63)-1;

struct Fenwick {
  LL t[N];
  void Init()
  {
    memset(t, 0, sizeof(t));
  }
  Fenwick& Add(int x, int y)
  {
    for (x++; x < N; x += -x&x) t[x] += y;
    return *this;
  }
  LL Ask(int x)
  {
    LL r = 0;
    for (x++; x; x -= -x&x) r += t[x];
    return r;
  }
  LL Ask(int x, int y)
  {
    return Ask(y)-Ask(x);
  }
};

struct Ans {
  Ans(LL c, LL h): c(c), h(h) {}
  friend bool operator < (const Ans& lhs, const Ans& rhs)
  {
    return lhs.c < rhs.c || (lhs.c == rhs.c && lhs.h > rhs.h);
  }
  friend ostream& operator << (ostream& lhs, const Ans& rhs)
  {
    if (rhs.c == oo) return lhs << -1;
    return lhs << rhs.h << " " << rhs.c;
  }
  LL c, h;
};

Fenwick zkl, cnt;
int n, w, h, p[3*N];

struct Update {
  Update(int lower, LL sum, LL all, Ans& ans)
      : lower(lower), sum(sum), all(all), ans(ans) {}
  Update& operator () (int h)
  {
    if (h < lower) return *this;
    LL pos = zkl.Ask(h, N-2)-cnt.Ask(h, N-2)*h, neg = cnt.Ask(h)*h-zkl.Ask(h), cost = max(pos, neg);
    if (neg-pos > all-sum) return *this;
    ans = min(Ans(cost, h), ans);
    return *this;
  }
  int lower;
  LL sum, all;
  Ans& ans;
};

int main()
{
  while (~scanf("%d%d%d", &n, &w, &h)) {
    fill(p, p+n+2*w, 0);
    LL all = 0;
    for (int i = w; i < n+w; i++) {
      scanf("%d", p+i);
      all += p[i];
    }
    Ans ans(oo, oo);
    zkl.Init();
    cnt.Init();
    LL sum = 0;
    for (int i = 0; i < w; i++) {
      sum += p[i];
      zkl.Add(p[i], p[i]);
      cnt.Add(p[i], 1);
    }
    for (int i = w; i < n+2*w; i++) {
      sum += p[i]-p[i-w];
      zkl.Add(p[i], p[i]).Add(p[i-w], -p[i-w]);
      cnt.Add(p[i], 1).Add(p[i-w], -1);
      Update(h, sum, all, ans)(h)(sum/w)((sum+w-1)/w);
    }
    cout << ans << endl;
  }
  return 0;
}
