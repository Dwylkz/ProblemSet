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

int n;

int main()
{
  scanf("%d", &n);
  if (n < 0)
    n *= -1;
  int sum = 0;
  for (int i = 0; ; i++) {
    sum += i;
    if (sum >= n && (sum-n)%2 == 0) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
