#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
const int maxn = 1e5 + 10;

int m, R;
double s[maxn];

int main()
{
  for ( ; ~scanf("%d%d", &m, &R); ) {
    for (int i = 0; i < m; i++)
      s[i] = 2+max(i-2, 0)*2+((i>0)+(i>1))*sqrt(2.0);
    for (int i = 1; i < m; i++)
      s[i] += s[i-1];
    double sum = 0;
    for (int i = 0; i < m; i++)
      sum += s[i]+s[m-i-1]-2.0;
    printf("%f\n", sum*R/(1.0*m*m));
  }
	return 0;
}
