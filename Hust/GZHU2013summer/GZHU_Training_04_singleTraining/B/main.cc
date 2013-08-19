#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 256;
typedef long long LL;

int n, d[maxn];
char buf[100100];

bool cmp(int lhs, int rhs)
{
  return lhs > rhs;
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%*[\n]", &n); ) {
    scanf("%[^\n]%*[\n]", buf);
    for (int i = 0; i < maxn; i++) d[i] = 0;
    for (int i = 0, l = strlen(buf); i < l; i++) d[buf[i]]++;
    sort(d, d+maxn, cmp);
    int sum = 0;
    for (int i = 0; d[i] && n-i; i++)
      sum += (n-i)*d[i];
    printf("%d\n", sum);
  }
  return 0;
}
