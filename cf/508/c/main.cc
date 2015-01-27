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

const int N = 3e2+5;

int m, t, r;
int l[N];

int main()
{
  scanf("%d%d%d", &m, &t, &r);
  memset(l, -1, sizeof(l));
  for (int i = 0; i < m; i++) {
    int wi;
    scanf("%d", &wi);
    l[wi] = wi;
  }
  for (int i = N-2; i >= 0; i--)
    if (l[i] == -1 && l[i+1] != -1)
      l[i] = l[i+1];
  // for (int i = 0; i < 12; i++)
  //   printf("%d%c", l[i], i < 11? ' ': '\n');
  int res = 0;
  queue<int> q;
  for (int i = l[1]-r; i < 0 || l[i] != -1; i++) {
    if (i < 0) {
      q.push(i+1);
      res++;
      while (q.size() > 0 && q.front()+t <= i+1)
        q.pop();
      continue;
    } else if (l[i] == i && q.size() < r) {
      puts("-1");
      return 0;
    }
    while (q.size() > 0 && q.front()+t <= i+1)
      q.pop();
    if (r-q.size() > 0 && l[i+1] != -1 && l[i+1]-i <= r-q.size()) {
      q.push(i+1);
      res++;
    }
  }
  printf("%d\n", res);
  return 0;
}
