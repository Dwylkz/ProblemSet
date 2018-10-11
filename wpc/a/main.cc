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
static const int N = 1e5+10;
static const int S = 256+10;

int n, m[S];
char a[N];

int main()
{
  m['I'] = 1;
  m['V'] = 5;
  m['X'] = 10;
  m['L'] = 50;
  m['C'] = 100;
  m['D'] = 500;
  m['M'] = 1000;
  while (~scanf("%d", &n))
  {
    while (n--)
    {
      scanf("%s", a);
      int l = strlen(a);
      int sum = 0;
      for (int i = 0; i < l; i++)
      {
        if (i+1 < l && m[a[i]] < m[a[i+1]] && 
            ((a[i] == 'I' && (a[i+1] == 'V' || a[i+1] == 'X'))
             || (a[i] == 'X' && (a[i+1] == 'L' || a[i+1] == 'C'))
             || (a[i] == 'C' && (a[i+1] == 'D' || a[i+1] == 'M'))
             ))
        {
          sum -= m[a[i]];
        }
        else
        {
          sum += m[a[i]];
        }
      }
      printf("%d\n", sum);
    }
  }
  return 0;
}
