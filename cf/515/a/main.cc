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

const char* Y = "Yes";
const char* N = "No";

int a, b, s;

int main()
{
  scanf("%d%d%d", &a, &b, &s);
  int d = abs(a)+abs(b);
  if (s >= d && s%2 == d%2) {
    puts(Y);
  } else {
    puts(N);
  }
  return 0;
}
