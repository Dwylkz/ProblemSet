#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 22e4+5;

char foo[N], bar[N];
int n, p[N];

int main()
{
  while (scanf("%s", foo) != EOF) {
    int bari = 0;
    bar[bari++] = '#';
    for (int i = 0; foo[i]; i++) {
      bar[bari++] = foo[i];
      bar[bari++] = '#';
    }
    bar[bari] = '\0';
    // puts(bar);
    int maxi = 0, res = 0;
    p[0] = 1;
    for (int i = 1; bar[i]; i++) {
      int j = 1;
      if (maxi+p[maxi] > i)
        j = min(p[maxi-(i-maxi)], maxi+p[maxi]-i);
      while (i-j >= 0 && bar[i+j] && bar[i-j] == bar[i+j])
        j++;
      p[i] = j;
      if (i+p[i] > maxi+p[maxi])
        maxi = i;
      res = max(res, p[i]);
    }
    // for (int i = 0; i < p.size(); i++)
    //   printf("%d%c", p[i], i<p.size()-1? ' ': '\n');
    printf("%d\n", res-1);
  }
  return 0;
}
