#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

int c[3];

int main()
{
  for (int i = 0; i < 3; i++)
    scanf("%d", c+i);

  sort(c, c+3);
  printf("%d\n", (int)min((1ll*c[0]+c[1]+c[2])/3, 1ll*c[0]+c[1]));
  return 0;
}
