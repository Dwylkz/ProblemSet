#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N = 1e2+10;

int m, s;

string F(string from)
{
  int t = s-1;
  for (char& c: from) {
    int d = min('9'-c, t);
    c += d;
    t -= d;
  }
  return from;
}

int main()
{
  scanf("%d%d", &m, &s);
  if ((m > 1 && s < 1) || s > m*9) {
    cout << -1 << " " << -1 << endl;
    return 0;
  }
  string minv(m, '0');
  minv[0] = '1';
  string maxv = minv;
  minv = F(minv);
  reverse(maxv.begin(), maxv.end());
  maxv = F(maxv);
  reverse(maxv.begin(), maxv.end());
  cout << maxv << " " << minv << endl;
  return 0;
}
