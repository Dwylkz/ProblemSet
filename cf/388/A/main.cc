#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef vector<PII> VPii;
const int N = 1e2+10;

int n;

bool cmp(const PII &lhs, const PII &rhs) {
  if (lhs.first != rhs.first) return lhs.first < rhs.first;
  return lhs.second > rhs.second;
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    VPii ps;
    for (int i = 0; i < n; i++) {
      int si;
      scanf("%d", &si);
      ps.push_back(PII(si, 1));
    }
    sort(ps.begin(), ps.end(), cmp);
    for (int i = 0; i < ps.size(); i++) {
      PII p = {-1, -1};
      for (int j = 0; j < i; j++)
        if (ps[j].second <= ps[i].first) {
          p = PII(ps[j].first, ps[j].second+ps[i].second);
          ps.erase(ps.begin()+i);
          ps.erase(ps.begin()+j);
          ps.push_back(p);
          break;
        }
      sort(ps.begin(), ps.end(), cmp);
      for (int j = 0; j < ps.size(); j++)
        if (ps[j] == p) {
          i = j-1;
          break;
        }
    }
    printf("%d\n", ps.size());
  }
  return 0;
}
