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

int n, a, b;

int main()
{
  scanf("%d%d%d", &n, &a, &b);
  printf("%d\n", ((a-1)+n+b)%n+1);
  return 0;
}
