#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 1e4+10;

typedef long long LL;
typedef vector<int> VI;

int n, np[N];
VI p;

int main()
{
  ios_base::sync_with_stdio(0);

  p.clear();
  memset(np, 0, sizeof(np));
  np[0] = np[1] = true;
  for (int i = 2; i < N; i++) {
    if (np[i])
      continue;
    p.push_back(i);
    for (int j = i*i; j < N; j += i)
      np[j] = true;
  }

  while (cin >> n) {
    LL ret = 0;
    for (int i = 0; i < p.size(); i++)
        for (int j = 0; j < p.size(); j++) {
          int k = n-p[i]-p[j];
          if (p[i] <= p[j] && p[j] <= k && !np[k])
            ret++;
        }
    cout << ret << endl;
  }
  return 0;
}
