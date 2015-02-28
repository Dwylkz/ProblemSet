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
#include <stdint.h>

using namespace std;

const int N = 1e5+5;
const int S = 256;

char s[N];
int n, val[S];

uint64_t DAC(int l, int r)
{
  if (r-l < 2)
    return 0;

  int m = (l+r)/2;
  uint64_t res = DAC(l, m)+DAC(m, r);

  map<uint64_t, int> ms[S];
  uint64_t sum = 0;
  for (int i = m-1; i >= l; i--) {
    ms[s[i]][sum]++;
    sum += val[s[i]];
  }

  sum = 0;
  for (int i = m; i < r; i++) {
    res += ms[s[i]][-sum];
    sum += val[s[i]];
  }

  return res;
}

int main()
{
  for (int i = 'a'; i <= 'z'; i++)
    scanf("%d", val+i);
  scanf("%s", s);
  cout << DAC(0, strlen(s)) << endl;
  return 0;
}
