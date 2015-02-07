#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-8;

struct Int {
  string val;

  Int(int val) {
    do {
      this->val += val%10;
      val /= 10;
    } while (val != 0);
  }

  string Str()
  {
    string ret = val;
    reverse(ret.begin(), ret.end());
    for (int i = 0; i < ret.size(); i++)
      ret[i] += '0';
    return ret;
  }

  void operator *= (const Int& rhs)
  {
    string ret(val.size()+rhs.val.size(), 0);
    for (int i = 0; i < val.size(); i++)
      for (int j = 0; j < rhs.val.size(); j++) {
        int w = val[i]*rhs.val[j]+ret[i+j];
        ret[i+j] = w%10;
        ret[i+j+1] += w/10;
      }
    int i = ret.size();
    while (i > 1 && ret[i-1] == 0)
      i--;
    while (i < ret.size() && ret[i-1] > 9) {
      ret[i] += ret[i-1]/10;
      ret[i-1] %= 10;
      i++;
    }
    val = ret.substr(0, i);
  }

  int Cmp(const Int& rhs)
  {
    if (val.size() > rhs.val.size())
      return 1;
    if (val.size() < rhs.val.size())
      return -1;
    for (int i = val.size(); i > 0; i--)
      if (val[i-1] > rhs.val[i-1])
        return 1;
      else if (val[i-1] < rhs.val[i-1])
        return -1;
    return 0;
  }
};

int a, b, c, d;

int main()
{
  while (~scanf("%d%d%d%d", &a, &b, &c, &d)) {
    double la = log(1.0*a)*b;
    double lb = log(1.0*c)*d;
    if (la < lb-EPS)
      puts("<");
    else if (la > lb+EPS)
      puts(">");
    else
      puts("=");
  }
  return 0;
}
