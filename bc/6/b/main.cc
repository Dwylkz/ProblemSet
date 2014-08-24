#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int n, k;

bool Check2(int square, int remain)
{
  int x = 0;
  for (int i = 0; i < k-1; i++) {
    if (++x == remain)
      x++;

    if (x > square)
      return false;

    square -= x;
  }

  if (!square || x+square != remain)
    return true;

  if (x == 1 || square == 1)
    return false;

  return true;
}

bool Check()
{
  for (int i = 1; i*i < n; i++) {
    int square = i*i;
    int remain = n-square;
    if (square < (k-1)*k/2)
      continue;

    if (Check2(square, remain))
      return true;
  }
  return false;
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> k) {
    puts(Check()? "YES": "NO");
  }
  return 0;
}
