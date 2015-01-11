#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int n, m;

int main()
{
  while (~scanf("%d%d", &n, &m)) {
    printf("%d\n", (m-1)%n);
  }
  return 0;
}
