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
static const int NN = 2e5+10;

int T, N, v[NN];

int main()
{
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &N);
    long long sum = 0;
    for (int i = 2; i <= N; i++)
    {
      v[i] = -1;
      for (int j = 0; (1<<j) < i && j < 32; j++)
      {
        if (((1<<j)&i) == 0)
        {
          v[i] = 1<<j;
          // cout << "fuck[" << j << "]: " << (1<<j) << endl;
          break;
        }
      }
      if (v[i] == -1)
      {
        if (i+1 <= N)
        {
          v[i] = i+1;
        }
        else
        {
          v[i] = 1;
          sum += 1;
        }
      }
      // cout << "v["<<i<<"]=" << v[i] << endl;
    }
    cout << sum << endl;
    for (int i = 2; i <= N; i++)
    {
      cout << v[i] << (i<N? ' ': '\n');
    }
  }
  return 0;
}
