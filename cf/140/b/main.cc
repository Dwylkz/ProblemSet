#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int N = 3e2+10;

int n, p[N][N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        cin >> p[i][j];
        p[i][j]--;
      }

    int b[N];
    for (int i = 0; i < n; i++) {
      int pi;
      cin >> pi;
      b[pi-1] = i;
    }

    int res[N];
    for (int i = 0; i < n; i++) {
        bool h[N] = {false};
        int now = -1;
        for (int j = 0; j < n; j++) {
          if (j == i || (~now && b[j] > b[now]))
            continue;

          now = j;
          h[now] = true;
        }

        for (int j = 0; j < n; j++) {
          if (!h[p[i][j]])
            continue;

          res[i] = p[i][j]+1;
          break;
        }
    }

    for (int i = 0; i < n-1; i++)
      cout << res[i] << " ";
    cout << res[n-1] << endl;
  }

  return 0;
}
