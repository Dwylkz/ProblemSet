#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 2e5+10;

int n, a[N], w, b[N];

void Show(int* a, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], i < n-1? ' ': '\n');
}

void ReadDiff(int *a, int n)
{
  int pre;
  scanf("%d", &pre);

  a[0] = 0;
  for (int i = 1; i < n; i++) {
    int cur;
    scanf("%d", &cur);
    a[i] = cur-pre;
    pre = cur;
  }

  // Show(a, n);
}

struct Kmp {
  static void ToAux(int* a, int n, int* aux)
  {
    int i = 0;
    int j = -1;
    while (i < n)
      if (j == -1) {
        aux[i] = j;
        i++;
        j++;
      }
      else if (a[i] == a[j]) {
        aux[i] = j;
        i++;
        j++;
      }
      else
        j = aux[j];

    // Show(aux, n);
  }

  static int Apply(int* a, int na, int* b, int nb)
  {
    static int aux[N];
    ToAux(b, nb, aux);

    int i = 0;
    int j = -1;
    int ret = 0;
    while (i < na)
      if (a[i] == b[j+1]) {
        i++;
        j++;

        if (j+1 == nb) {
          j = aux[j];
          ret++;
        }
      }
      else if (j == -1)
        i++;
      else
        j = aux[j];
    return ret;
  }
};

int main()
{
  scanf("%d%d", &n, &w);
  ReadDiff(a, n);
  ReadDiff(b, w);
  printf("%d\n", w == 1? n: Kmp::Apply(a+1, n-1, b+1, w-1));
  return 0;
}
