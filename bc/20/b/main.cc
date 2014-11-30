#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 2e5+5;

typedef pair<int, int> PII;
typedef map<int, int> MII;

int n, a[N];
PII p[N];

int main()
{
  int kase;
  scanf("%d", &kase);
  while(kase--) {
    scanf("%d", &n);
    MII dis;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &p[i].first, &p[i].second);
      dis[p[i].first] = 0;
      dis[p[i].second] = 0;
    }
    int id = 0;
    for (MII::iterator i = dis.begin(); i != dis.end(); i++)
      i->second = id++;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
      a[p[i].first]++;
      a[p[i].second+1]--;
    }
    int maxv = a[0];
    for (int i = 1; i < N; i++) {
      a[i] += a[i-1];
      maxv = max(maxv, a[i]);
    }
    printf("%d\n", maxv);
  }
  return 0;
}
