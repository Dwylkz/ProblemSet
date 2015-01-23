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
#include <bitset>

using namespace std;

const int N = 2e3+5;

typedef bitset<N> BS;

int Div(string& foo)
{
  int mod = 0;
  for (int i = foo.size()-1; i >= 0; i--) {
    int div = (foo[i]-'0')+mod*10;
    foo[i] = div/2+'0';
    mod = div%2;
    if (foo[i] == '0' && i > 0)
      foo.pop_back();
  }
  return mod;
}

int Str2BS(string& foo, BS& b)
{
  reverse(foo.begin(), foo.end());

  int i = 0;
  while (foo != "0")
    b[i++] = Div(foo);
  return i;
}

BS bs[N], use[N];
int m, fst[N];

void Reduce(int x, int maxbit)
{
  for (int i = maxbit-1; i >= 0; i--)
    if (bs[x][i]) {
      if (fst[i] == -1)
        return ;
      bs[x] ^= bs[fst[i]];
      use[x] ^= use[fst[i]];
      use[x].flip(fst[i]);
    }
}

void Print(int x)
{
  int size = use[x].count();
  cout << size;
  for (int i = 0; i < m; i++)
    if (use[x][i])
      cout << " " << i;
  cout << "\n";
}

void SetFst(int x, int maxbit)
{
  for (int i = maxbit-1; i >= 0; i--)
    if (bs[x][i]) {
      fst[i] = x;
      return ;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin >> m;
  int maxbit = 0;
  for (int i = 0; i < m; i++) {
    string foo;
    cin >> foo;
    maxbit = max(maxbit, Str2BS(foo, bs[i]));
    // cout << bs[i] << "\n";
  }
  for (int i = 0; i < maxbit; i++)
    fst[i] = -1;
  for (int i = 0; i < m; i++) {
    Reduce(i, maxbit);
    if (bs[i].none())
    // if (true)
      Print(i);
    else
      cout << "0\n";
    SetFst(i, maxbit);
  }
  return 0;
}
