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

const int N = 8;
const int M = 4*8+7+1;

typedef vector<int> VI;

int n;
char foo[M];

VI Extract(char* src)
{
  VI dst;
  char* tail = src+strlen(src);
  while (src < tail) {
    char* upper = strchr(src, ':');
    if (upper == NULL)
      upper = tail;
    *upper = '\0';
    dst.push_back(0);
    sscanf(src, "%x", &dst.back());
    src = upper+1;
  }
  return dst;
}

int main()
{
  scanf("%d", &n);
  while (n--) {
    scanf("%s", foo);
    char *z = strstr(foo, "::");
    if (z != NULL)
      *z = '\0';
    VI pre, suf;
    pre = Extract(foo);
    if (z != NULL)
      suf = Extract(z+2);
    VI ans(N-pre.size()-suf.size(), 0);
    ans.insert(ans.begin(), pre.begin(), pre.end());
    ans.insert(ans.end(), suf.begin(), suf.end());
    for (int i = 0; i < (int)ans.size(); i++)
      printf("%04x%c", ans[i], (i < (int)ans.size()-1)? ':': '\n');
  }
  return 0;
}
