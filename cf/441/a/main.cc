#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, v;

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> v) {
    vector<int> res;
    for (int i = 0; i < n; i++) {
      bool in = false;
      int ki;
      cin >> ki;
      for (int j = 0; j < ki; j++) {
        int sij;
        cin >> sij;
        if (sij < v && !in) {
          res.push_back(i+1);
          in = true;
        }
      }
    }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
      printf("%d%c", res[i], i < res.size()-1? ' ': '\n');
    if (!res.size())
      puts("");
  }
  return 0;
}
