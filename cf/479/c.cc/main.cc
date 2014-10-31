#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N = 5e3+5;

typedef pair<int, int> PII;
typedef vector<PII> VPii;

int n, f[N];

int main()
{
  VPii ps;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ps.push_back(PII(a, b));
  }
  sort(ps.begin(), ps.end());

  f[0] = ps[0].second;
  for (int i = 1; i < ps.size(); i++)
    if (f[i-1] <= ps[i].second) {
      f[i] = ps[i].second;
    }
    else {
      f[i] = ps[i].first;
    }
  printf("%d\n", f[n-1]);
  return 0;
}
