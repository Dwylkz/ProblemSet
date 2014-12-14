#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int a[4];

bool Case1()
{
  int b[4];
  memcpy(b, a, sizeof(b));
  return false;
}

int main()
{
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    const char* ans[] = {"No", "Yes"};
    for (int i = 0; i < 4; i++)
      scanf("%d", a+i);
  }
  return 0;
}
