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

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%s", d[i]);
  int c = 0;
  for (int i = 0; i < n; i++) {
    int l = strlen(d[i]);
    string foo = Conv<string>(c);
    bool need = foo.size() == l;
    // printf("%s,%lu and %s,%d\n", foo.data(), foo.size(), d[i], l);
    if (need) {
      for (int j = l-1; j >= 0; j--) {
        if (d[i][j] != '?')
          continue;
        if (need) {
          if (foo.substr(j+1) >= string(d[i]).substr(j+1)) {
            if (foo[j] <= '9') {
              d[i][j] = foo[j]+1;
              need = false;
            }
            else
              d[i][j] = foo[j];
          }
          else
            d[i][j] = foo[j];
        }
        else
          d[i][j] = foo[j];
      }
    }
    else {
      for (int j = l-1; j >= 1; j--)
        if (d[i][j] == '?')
          d[i][j] = '0';
      if (d[i][0] == '?')
        d[i][0] = '1';
      // printf("%d, %d: no need %s\n", c, i, d[i]);
    }
    int tc = Conv<int>(d[i]);
    if (foo.size() > l || tc <= c) {
      // printf("%s <= %d\n", d[i], c);
      puts("NO");
      return 0;
    }
    c = tc;
  }
  puts("YES");
  for (int i = 0; i < n; i++)
    puts(d[i]);
  return 0;
}
