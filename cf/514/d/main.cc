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

const int N = 1e5+5;
const int M = 5+5;

struct MS
{
  typedef pair<int, int> PII;

  deque<PII> s;

  void Push(int x, int y)
  {
    while (s.size() > 0 && s.back().second < y) {
      s.pop_back();
    }
    s.push_back(PII(x, y));
  }

  PII& Top()
  {
    return s.front();
  }

  void Pop(int x)
  {
    if (s.front().first == x) {
      s.pop_front();
    }
  }
};

MS ms[M];
int n, m, k;

int Sum()
{
  int res = 0;
  for (int i = 0; i < m; i++) {
    res += ms[i].Top().second;
  }
  return res;
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  int res[M] = {0}, maxv = 0, head = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int ai;
      scanf("%d", &ai);
      ms[j].Push(i-1, ai);
    }
    while (head < i && Sum() > k) {
      for (int j = 0; j < m; j++) {
        ms[j].Pop(head);
      }
      head++;
    }
    if (i-head > maxv) {
      maxv = i-head;
      for (int j = 0; j < m; j++) {
        res[j] = ms[j].Top().second;
      }
    }
  }
  // printf("maxv = %d\n", maxv);
  for (int i = 0; i < m; i++) {
    printf("%d%c", res[i], (i < m-1? ' ': '\n'));
  }
  return 0;
}
