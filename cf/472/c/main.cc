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
const int N = 1e5+10;

int n, p[N];
string a[N][2];
bool isok[N][2];

int main()
{
  cin.sync_with_stdio(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i][0] >> a[i][1];

  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  isok[0][0] = isok[0][1] = true;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      if (!isok[i-1][j])
        continue;

      for (int k = 0; k < 2; k++)
        if (a[p[i-1]][j] < a[p[i]][k])
          isok[i][k] = true;
    }
  }

  if (isok[n-1][0] || isok[n-1][1])
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
