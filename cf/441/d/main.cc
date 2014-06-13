#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e3+10;

int n, m, p[N];

int tag[N];
int Tag()
{
  int id = 0;
  fill(tag, tag+n, -1);
  for (int i = 0; i < n; i++) {
    if (~tag[i])
      continue;

    tag[i] = id;
    for (int j = p[i]; j != i; j = p[j])
      tag[j] = id;

    id++;
  }
  return id;
}

int RingMin(int i) 
{
  int res = n;
  for (int j = p[i]; j != i; j = p[j])
    res = min(res, j);
  return res;
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
    }
    cin >> m;

    int c = Tag();
    cout << abs(n-m-c) << endl;

    int res = 0;
    while (c != n-m) {
      if (c < n-m) {
        int i = find_if(p, p+n, [&](int x){return p[x] != x;})-p;
        int j = RingMin(i);
        cout << i+1 << " " << j+1;
        swap(p[i], p[j]);
      }
      else {
        int i = find_if(tag, tag+n, [&](int x){return x;})-tag;
        cout << 1 << " " << i+1;
        swap(p[0], p[i]);
      }

      c = Tag();
      if (c == n-m)
        cout << endl;
      else
        cout << " ";
    }
  }
  return 0;
}
