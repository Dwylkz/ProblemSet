#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1e6+10;
typedef long long LL;

struct point_t {
  int x, y, i;
  point_t(int _x = 0, int _y = 0, int _i = 0): x(_x), y(_y), i(_i) {}
  friend bool operator < (const point_t &lhs, const point_t &rhs) {
    return lhs.x < rhs.x;
  }
  friend bool operator > (const point_t &lhs, const point_t &rhs) {
    return lhs.y < rhs.y;
  }
  friend bool operator <= (const point_t &lhs, const point_t &rhs) {
    return lhs.x == rhs.x? lhs.y < rhs.y: lhs.x < rhs.x;
  }
};

int n;
vector<point_t> p;
LL pre[N], sum[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int kas = 1; kas <= T; kas++) {
    printf("Case #%d: ", kas);
    scanf("%d", &n);
    p.clear();
    for (int i = 0; i < n; i++) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      for (int x = x1; x <= x2; x++)
        for (int y = y1; y <= y2; y++)
          p.push_back(point_t(x, y, p.size()));
    }
    memset(sum, 0, sizeof(sum));
    // deal x
    sort(p.begin(), p.end());
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i < p.size(); i++) {
      pre[i] = pre[i-1]+(1ll*p[i].x-p[i-1].x)*i;
      sum[p[i].i] += pre[i];
    }
    memset(pre, 0, sizeof(pre));
    for (int i = p.size()-2; ~i; i--) {
      pre[i] = pre[i+1]+(1ll*p[i+1].x-p[i].x)*(p.size()-1-i);
      sum[p[i].i] += pre[i];
    }
    // deal y
    sort(p.begin(), p.end(), greater<point_t>());
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i < p.size(); i++) {
      pre[i] = pre[i-1]+(1ll*p[i].y-p[i-1].y)*i;
      sum[p[i].i] += pre[i];
    }
    memset(pre, 0, sizeof(pre));
    for (int i = p.size()-2; ~i; i--) {
      pre[i] = pre[i+1]+(1ll*p[i+1].y-p[i].y)*(p.size()-1-i);
      sum[p[i].i] += pre[i];
    }
    int result = 0;
    for (int i = 1; i < p.size(); i++)
      if (sum[p[i].i] == sum[p[result].i] && p[i] <= p[result]
          || sum[p[i].i] < sum[p[result].i])
        result = i;
    cout << p[result].x << " " << p[result].y << " " << sum[p[result].i] << endl;
  }
  return 0;
}
