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

int main()
{
  int T, n, b;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d%d", &n, &b);
    bool yes = false;
    for (int i = 0; i < n; i++)
    {
      int a;
      scanf("%d", &a);
      if ((a+b)%7 == 0)
      {
        yes = true;
      }
    }
    puts(yes? "Yes": "No");
  }
  return 0;
}
