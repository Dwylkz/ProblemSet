#include <algorithm>
#include <numeric>
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

const int N = 1<<5;

int n;
char t[N];
vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
  scanf("%d %*s %s", &n, t);
  int sum = accumulate(month.begin(), month.end(), 0);
  int cnt = 0;
  if (!strcmp(t, "week")) {
    int d = 4;
    for (int i = 0; i < sum; i++) {
      if (n-1 == d) cnt++;
      d = (d+1)%7;
    }
  } else {
    for (int& l: month)
      if (n <= l) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
