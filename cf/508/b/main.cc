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

const int N = 1e5+5;
const int B = 10;

char n[N];

int main()
{
  scanf("%s", n);
  int last = strlen(n)-1;
  int h[B];
  memset(h, -1, sizeof(h));
  for (int i = 0; n[i+1]; i++)
    if (~n[i]&1) {
      int d = n[i]-'0';
      if (n[i] < n[last]) {
        if (h[d] == -1)
          h[d] = i;
      } else {
        h[d] = i;
      }
    }
  int res = -1;
  for (int i = 0; i < n[last]-'0'; i++)
    if ((~i&1) && h[i] != -1) {
      if (res == -1 || h[i] < res)
        res = h[i];
    }
  if (res != -1) {
    swap(n[res], n[last]);
    puts(n);
    return 0;
  }
  res = -1;
  for (int i = n[last]-'0'+1; i < B; i++)
    if ((~i&1) && h[i] != -1) {
      if (res == -1 || h[i] > res)
        res = h[i];
    }
  if (res != -1) {
    swap(n[res], n[last]);
    puts(n);
    return 0;
  }
  puts("-1");
  return 0;
}
