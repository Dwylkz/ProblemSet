#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    int ci;
    scanf("%d", &ci);
    sum += ci;
  }
  if (sum%5 || sum/5 == 0)
    printf("-1\n");
  else
    printf("%d\n", sum/5);
  return 0;
}
