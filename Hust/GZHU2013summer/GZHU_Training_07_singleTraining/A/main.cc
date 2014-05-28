#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long LL;

vector<LL> s;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  LL o = 1;
  for (int i = 0; i < 63; i++)
    s.push_back(o *= 2);
  o = 1;
  for (int i = 0; i < 41; i++)
    s.push_back(o *= 3);
  sort(s.begin(), s.end());
#if 0
  printf("size = %ld\n", s.size());
  for (int i = 0; i < s.size(); i++) printf("%llu ", s[i]);
  puts("");
#endif
  for (int n; ~scanf("%d", &n); ) {
    printf("%llu\n", s[n-1]);
  }
  return 0;
}
