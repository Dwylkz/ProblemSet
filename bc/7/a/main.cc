#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <cstring>
#include <numeric>
#include <vector>
#include <sstream>

using namespace std;

const int N = 1e5+10;

int n, d[N], b[N];

vector<int> p;
void Dfs(int u)
{
  if (b[u])
    return ;

  b[u] = 1;
  p.push_back(u);
  Dfs(d[u]);
}

string Merge(vector<int>& v)
{
  stringstream ret;
  ret << "(";
  for (int i = 0; i < v.size()-1; i++)
    ret << v[i] << " ";
  ret << v.back() << ")";
  return ret.str();
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n) {
    for (int i = 1; i <= n; i++)
      cin >> d[i];

    vector<string> ret;
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++) {
      if (b[i])
        continue;

      p.clear();
      Dfs(i);
      ret.push_back(Merge(p));
    }

    for (int i = 0; i < ret.size(); i++)
      cout << ret[i];
    cout << endl;
  }
  return 0;
}
