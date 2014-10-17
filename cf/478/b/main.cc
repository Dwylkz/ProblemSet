#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, m;

long long F(int x)
{
  return 1ll*(x-1)*x/2;
}

int main()
{
  scanf("%d%d", &n, &m);
  long long ave = n/m;
  long long minval = 1ll*n*n;
  long long maxval = F(n-(m-1));
  if (n%m)
    minval = F(ave)*(m-n%m)+F(ave+1)*(n%m);
  else
    minval = F(ave)*m;
  cout << minval << " " << maxval << endl;
  return 0;
}
