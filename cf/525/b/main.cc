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

const int N = 2e5+5;

int n, m, d[N];
char s[N];

int main()
{
  scanf("%s%d", s, &n);
  int ns = strlen(s);
  fill(d, d+ns, 0);
  while (n--) {
    int ai;
    scanf("%d", &ai);
    d[ai-1] ^= 1;
  }
  for (int i = 1; i < ns/2; i++) d[i] ^= d[i-1];
  for (int i = 0; i < ns/2; i++)
    if (d[i]) swap(s[i], s[ns-1-i]);
  puts(s);
  return 0;
}
