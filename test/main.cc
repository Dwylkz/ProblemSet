#include <fstream>
#include <iostream>
#include <vector>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <cstdarg>
using namespace std;

const int N = 1<<16;
const int M = N*2+5;

int tag[M], l[M], r[M];

void Init()
{
  memset(tag, 0, sizeof(tag));
  memset(l, -1, sizeof(l));
  memset(r, -1, sizeof(r));
  for (int i = N; i < N*2; i++) {
    l[i] = r[i] = i-N;
    for (int j = i; j; j >>= 1) {
      if (l[j] == -1 || l[j] > l[i])
        l[j] = l[i];
      if (r[j] == -1 || r[j] < r[i])
        r[j] = r[i];
    }
  }
}

void Add(int h, int t, int x)
{
  h += N;
  t += N+2;
  while (h^t^1) {
    if (~h&1)
      tag[h^1] += x;
    if (t&1)
      tag[t^1] += x;
    h >>= 1;
    t >>= 1;
  }
  while (h) {
    tag[h] += x;
    h >>= 1;
  }
}

int Ask(int h, int t)
{
  int ret = 0;
  h += N;
  t += N+2;
  while (h^t^1) {
    if (~h&1)
      ret += (r[h^1]-l[h^1]+1)*tag[h^1];
    if (t&1)
      ret += (r[t^1]-l[t^1]+1)*tag[t^1];
    h >>= 1;
    t >>= 1;
  }
  while (h) {
    ret += (r[h]-l[h]+1)*tag[h];
    h >>= 1;
  }
  return ret;
}

int n, a[N];

int main()
{
  Init();
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 1; i < n; i++)
    a[i] += a[i-1];
  int t;
  while (~scanf("%d", &t)) {
    int x, y, z;
    if (t == 1) {
      scanf("%d%d", &x, &y);
      printf("%d\n", Ask(x, y)+a[y]-(x > 0? a[x-1]: 0));
    } else {
      scanf("%d%d%d", &x, &y, &z);
      Add(x, y, z);
    }
  }
  return 0;
}
