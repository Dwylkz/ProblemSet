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

typedef long long LL;
typedef vector<LL> VLl;

int GCD(int a, int b)
{
  if (b == 0)
    return a;
  return GCD(b, a%b);
}

LL LCM(LL a, LL b)
{
  return 1ll*a*b/GCD(a, b);
}

int n, x, y;

int main()
{
  scanf("%d%d%d", &n, &x, &y);
  LL lcm = LCM(x, y);
  LL dx = lcm/x;
  LL dy = lcm/y;
  VLl s;
  for (LL xi = dx, yi = dy; xi <= lcm || yi <= lcm; )
    if (xi == yi) {
      s.push_back(2);
      xi += dx;
      yi += dy;
    }
    else if (xi > yi || xi > lcm) {
      s.push_back(1);
      yi += dy;
    }
    else if (yi > xi || yi > lcm) {
      s.push_back(0);
      xi += dx;
    }
  // for (int i = 0; i < s.size(); i++)
  //   cout << s[i] << " ";
  // cout << endl;
  VLl h(s);
  for (int i = 0; i < h.size(); i++) {
    h[i] = s[i] < 2? 1: 2;
    if (i > 0)
      h[i] += h[i-1];
  }
  // for (int i = 0; i < h.size(); i++)
  //   cout << h[i] << ' ';
  // cout << endl;
  string ans[] = {"Vanya", "Vova", "Both"};
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    ai %= h.back();
    if (ai == 0) {
      puts(ans[s.back()].data());
      continue;
    }
    int l = 0, r = h.size();
    while (l < r) {
      int m = (l+r)/2;
      if (h[m] <= ai)
        l = m+1;
      else
        r = m;
    }
    if (l > 0 && h[l-1] >= ai)
      l--;
    puts(ans[s[l]].data());
  }
  return 0;
}
