#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 50+10;

int n, m, in[N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m) {
    memset(in, 0, sizeof(in));
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      in[v-1]++;
    }

    int head = 0;
    for (int i = 0; i < n; i++)
      if (in[i] == 0)
        head++;

    cout << (1ll<<n-head)<< endl;
  }
  return 0;
}
