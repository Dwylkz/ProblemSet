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

const int N = 2e5+5;

int n, w, h, p[N];

void Ass(LL a, LL s, LL& p, LL& n)
{
  if (a >= 0) p += a*s;
  else n += -1*a*s;
}

int main()
{
  while (~scanf("%d%d%d", &n, &w, &h)) {
    fill(p, p+n+2*w, 0);
    LL all = 0;
    for (int i = w; i < n+w; i++) {
      scanf("%d", p+i);
      all += p[i];
    }
    LL minv = B(), maxh = h;
    if (minv == -1) {
      puts("-1");
      continue;
    }

    LL pos = 0, neg = 0, sum = 0, hs = 0;
    for (int i = 0; i < w-1; i++) {
      sum += p[i];
      Ass(p[i]-h, 1, pos, neg);
    }
    for (int i = w-1; i < n+2*w; i++) {
      Ass(p[i]-h, 1, pos, neg);
      sum += p[i];
      if (i-w >= 0) {
        Ass(p[i-w]-h, -1, pos, neg);
        sum -= p[i-w];
      }
      LL h2 = 2ll*w*h, pot = h2-sum;
      if (h2 >= sum) continue;
      h = sum/2;
      LL cost = min(pos);
    }
    cout << minv << endl;
  }
  return 0;
}
