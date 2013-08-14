#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 256;
typedef long long LL;

char buf[100000];

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%[^\n]\n", buf); ) {
    printf("|x| < 0 => %s\n", buf);
  }
  return 0;
}
