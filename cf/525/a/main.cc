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

int n;
char s[N];

int main()
{
  scanf("%d%s", &n, s);
  map<char, int> ks;
  int ret = 0;
  for (int i = 0; i < n-1; i++) {
    int k = toupper(s[i*2]), d = s[i*2+1];
    ks[k]++;
    if (ks[d] > 0) ks[d]--;
    else ret++;
  }
  printf("%d\n", ret);
  return 0;
}
