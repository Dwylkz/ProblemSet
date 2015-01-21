#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 1e3+5;
const int B = 64;

typedef long long LL;

int n;
LL a[N];

int main()
{
  ios_base::sync_with_stdio(0);
  int kase;
  cin >> kase;
  while (kase--) {
    cin >> n;
    int maxbit = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = B-1; j >= 0; j--)
        if (a[i]>>j&1) {
          maxbit = max(maxbit, j+1);
          break;
        }
    }
    bool yes = false;
    for (int i = 0; i < min(maxbit, n); i++) {
      int j = i;
      while (j < n && (~a[j]>>(maxbit-1-i)&1))
        j++;
      if (j == n) {
        yes = true;
        break;
      }
      swap(a[i], a[j]);
      for (int k = i+1; k < n; k++)
        if (a[k]>>(maxbit-1-i)&1)
          a[k] ^= a[j];
    }
    puts(yes || (maxbit < n)? "Yes": "No");
  }
  return 0;
}
