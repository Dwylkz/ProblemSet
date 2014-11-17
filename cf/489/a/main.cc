#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N = 3e3+10;

int n, a[N], l[N], r[N];

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    int j = min_element(a+i, a+n)-a;
    swap(a[i], a[j]);
    printf("%d %d\n", i, j);
  }
  // for (int i = 0; i < n; i++)
  //   printf("%d ", a[i]);
  return 0;
}
