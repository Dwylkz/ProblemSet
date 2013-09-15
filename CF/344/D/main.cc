#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;

char p[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", p); ) {
    int n = strlen(p);
    if (n&1) {
      puts("No");
      continue;
    }
    vector<char> v;
    for (int i = 0; i < n; i++)
      if (v.size() && v.back() == p[i]) v.pop_back();
      else v.push_back(p[i]);
    puts(!v.size()? "Yes": "No");
  }
  return 0;
}
