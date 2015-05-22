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

int k, n, w;

int main()
{
  scanf("%d%d%d", &k, &n, &w);
  printf("%d\n", max(0, (1+w)*w/2*k-n));
  return 0;
}
