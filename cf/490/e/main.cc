#include <sstream>
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
const int M = 8+5;

int n;
char d[N][M];

template<typename T, typename F> T Conv(F from)
{
    stringstream ss;
    ss << from;
    T foo;
    ss >> foo;
    return foo;
}

bool Constract(char* lhs, char* rhs)
{
  return true;
}

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%s", d[i]);
  d[0][0] = '0';
  for (int i = 1; i <= n; i++)
    if (!Constract(d[i-1], d[i])) {
      puts("NO");
      return 0;
    }
  puts("YES");
  for (int i = 0; i < n; i++)
    puts(d[i]);
  return 0;
}
