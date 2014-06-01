#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  cin.sync_with_stdio(0);
  string c[4];
  for (int i = 0; i < 4; i++)  {
    cin >> c[i];
    c[i] = c[i].substr(2, c[i].size()-2);
  }

  int cnt = 0, ci = -1;
  for (int i = 0; i < 4; i++) {
    bool yes = 1;
    for (int j = 1; j < 4; j++) {
      int k = (i+j)%4;
      if (c[i].size() < 2*c[k].size())
        yes = 0;
    }
    if (yes) {
      cnt++;
      ci = i;
      continue;
    }

    yes = 1;
    for (int j = 1; j < 4; j++) {
      int k = (i+j)%4;
      if (2*c[i].size() > c[k].size())
        yes = 0;
    }
    if (yes) {
      cnt++;
      ci = i;
    }
  }

  if (cnt == 1)
    cout << (char)('A'+ci) << endl;
  else
    cout << 'C' << endl;
  return 0;
}
