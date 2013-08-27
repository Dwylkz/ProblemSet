#include <map>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int N = 2e3 + 10;

char b[N];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%s", b); ) {
    vector<int> v;
    for (char *s = b, op[10]; *s && ~sscanf(s, "%1s", op); s++)
      if (*op != '+') v.push_back(*op-'0');
    sort(v.begin(), v.end());
    int b = 0;
    for (int i = 0; i < v.size(); i++) {
      if (b) putchar('+');
      b = 1;
      printf("%d", v[i]);
    }
    puts("");
  }
	return 0;
}
