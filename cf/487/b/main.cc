#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cctype>

using namespace std;

typedef deque<int> MQ;

const int N = 1e5+10; 
const int S = 1e6;

int n, s, l, a[N], g[N], f[N];

int main()
{
  scanf("%d%d%d", &n, &s, &l);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  MQ maxq, minq;
  for (int head = 0, i = 0; i < n; i++) {
    while (!maxq.empty())
      if (maxq.front() < head)
        maxq.pop_front();
      else if (abs(a[maxq.front()]-a[i]) > s) {
        head = maxq.front()+1;
        maxq.pop_front();
      }
      else
        break;
    while (!minq.empty())
      if (minq.front() < head)
        minq.pop_front();
      else if (abs(a[minq.front()]-a[i]) > s) {
        head = minq.front()+1;
        minq.pop_front();
      }
      else
        break;
    g[i] = head;
    while (!maxq.empty() && a[maxq.back()] < a[i])
      maxq.pop_back();
    maxq.push_back(i);
    while (!minq.empty() && a[minq.back()] > a[i])
      minq.pop_back();
    minq.push_back(i);
  }
  // for (int i = 0; i < n; i++)
  //   printf("%d%c", g[i], i < n-1? ' ': '\n');
  MQ fq;
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (i >= l) {
      while (!fq.empty() && f[i-l] < f[fq.back()])
        fq.pop_back();
      fq.push_back(i-l);
    }
    while (!fq.empty() && fq.front() < g[i-1])
      fq.pop_front();
    // printf("fq: ");
    // for (int j = 0; j < fq.size(); j++)
    //   printf("%d ", fq[j]);
    // puts("");
    if (fq.empty())
      f[i] = n+1;
    else
      f[i] = f[fq.front()]+1;
  }
  // for (int i = 0; i <= n; i++)
  //   printf("%d ", f[i]);
  // puts("");
  if (f[n] > n)
    f[n] = -1;
  printf("%d\n", f[n]);
  return 0;
}
