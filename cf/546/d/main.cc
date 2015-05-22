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

const int N = 5e6+5;

int t, nf[N], mf[N];
bool isp[N];
vector<int> p;

void Sieve()
{
  for (int i = 2; i < N; i++) {
    if (!isp[i]) {
      p.push_back(i);
      nf[i] = 1;
      mf[i] = 1;
    }
    for (int j = 0; j < p.size(); j++) {
      int k = i*p[j];
      if (k >= N) break;
      isp[k] = true;
      if (i%p[j]) {
        mf[k] = 1;
        nf[k] = nf[i]+mf[k];
      } else {
        mf[k] = mf[k]+1;
        nf[k] = nf[i]+mf[k];
        break;
      }
    }
  }
}

int main()
{
  Sieve();
  for (int i = 2; i < N; i++) nf[i] += nf[i-1];
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", nf[a]-nf[b]);
  }
  return 0;
}
