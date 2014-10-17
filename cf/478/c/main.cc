#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int c[3];

int main()
{
  for (int i = 0; i < 3; i++)
    scanf("%d", c+i);

  int maxval = *min_element(c, c+3);
  int p[3] = {0, 1, 2};
  do {
    int t[3];
    for (int i = 0; i < 3; i++)
      t[i] = c[p[i]];

    int val = min(t[0]/2, t[1]);
    t[0] -= val*2;
    t[1] -= val;
    val += min(t[0]+t[1], t[2]/2);

    maxval = max(maxval, val);
  } while (next_permutation(p, p+3));
  printf("%d\n", maxval);
  return 0;
}
