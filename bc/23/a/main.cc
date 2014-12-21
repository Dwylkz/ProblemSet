#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 1e3+5;

int n, a[N];

bool IsPalindrome()
{
  for (int i = 0; i < n/2; i++)
    if (a[i] != a[n-1-i])
      return false;
  return true;
}

int main()
{
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d", &n);
    int s[2] = {0};
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      s[i&1] += a[i];
    }
    puts(s[0] == s[1] && !IsPalindrome()? "Yes": "No");
  }
  return 0;
}
