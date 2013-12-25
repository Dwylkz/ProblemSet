#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 5e3+10;

int n, m, a[N][N];
char buff[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < n; i++) {
      scanf("%s", buff);
      for (int j = 0; j < m; j++)
        a[i][j] = buff[j]-'0';
    }
    vector<vector<int> > s(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (!a[i][j]) continue;
        int k;
        s[i][j] = 1;
        for (k = j+1; k < m && a[i][k]; k++)
          s[i][j]++;
        for (int l = j+1; l < k; l++)
          s[i][l] = s[i][j]-(l-j);
        j = k-1;
      }
    int result = 0;
    for (int i = 0; i < m; i++) {
      vector<int> h(m+1);
      for (int j = 0; j < n; j++)
        h[s[j][i]]++;
      for (int j = m-1; ~j; j--)
        h[j] += h[j+1];
      for (int j = i+1; j <= m; j++)
        result = max(result, h[j-i]*(j-i));
    }
    printf("%d\n", result);
  }
  return 0;
}
