#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 3e2+10;
typedef pair<int, int> PII;

int n, m, k;

PII Next(PII cur)
{
  if (cur.first%2 == 0) {
    if (cur.second == m-1)
      return PII(cur.first+1, m-1);
    return PII(cur.first, cur.second+1);
  }
  if (cur.second == 0)
    return PII(cur.first+1, 0);
  return PII(cur.first, cur.second-1);
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m >> k) {
    PII cur(0, 0);
    for (int i = 0; i < k-1; i++) {
      printf("2 %d %d", cur.first+1, cur.second+1);
      cur = Next(cur);
      printf(" %d %d\n", cur.first+1, cur.second+1);
      cur = Next(cur);
    }

    printf("%d %d %d", n*m-2*(k-1), cur.first+1, cur.second+1);
    for (int i = 0; i < n*m-2*(k-1)-1; i++) {
      cur = Next(cur);
      printf(" %d %d", cur.first+1, cur.second+1);
    }
    puts("");
  }
  return 0;
}
