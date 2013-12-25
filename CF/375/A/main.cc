#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6+10;
const int MOD = 7;

char s[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  int p[] = {1, 6, 8, 9}, h[MOD] = {0};
  do {
    int sum = p[0]*1000+p[1]*100+p[2]*10+p[3];
    if (!h[sum%MOD]) h[sum%MOD] = sum;
  } while(next_permutation(p, p+4));
  for ( ; ~scanf("%s", s); ) {
    int n = strlen(s);
    sort(s, s+n, greater<char>());
    vector<int> a, b = {1, 6, 8, 9};
    for (int i = 0; i < n; i++)
      if (s[i]-'0' == b.back()) b.pop_back();
      else a.push_back(s[i]-'0');
    int i, r = 0;
    for (i = 0; i < a.size() && a[i]; i++) {
      putchar(a[i]+'0');
      r = (r*10+a[i])%MOD;
    }
    printf("%d", h[(MOD-r*10000%MOD)%MOD]);
    for ( ; i < a.size(); i++) putchar('0');
    puts("");
  }
  return 0;
}
