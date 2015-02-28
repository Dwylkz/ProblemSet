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


map<int, int> ce[2];
int n;

void Read(int n, int ro)
{
  ce[ro].clear();
  for (int i = 0; i < n; i++) {
    int num = 0;
    scanf("%d", &num);
    ce[ro][num]++;
  }
}

void Miss(int ro)
{
  for (auto cei: ce[ro])
    if (ce[ro^1][cei.first] != cei.second) {
      printf("%d\n", cei.first);
      return ;
    }
}

int main()
{
  scanf("%d", &n);
  Read(n, 0);
  Read(n-1, 1);
  Miss(0);
  Read(n-2, 0);
  Miss(1);
  return 0;
}
