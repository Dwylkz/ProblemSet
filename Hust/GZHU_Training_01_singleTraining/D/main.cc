#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cctype>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

string s[2], ss[2];

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
  s[0] = s[1] = "";
	for (int sc = 0, c; ~(c = getchar()); )
    if (c == '-') {
      sc++;
      if (sc == 2) {
        ss[0] = ss[1] = "";
        for (int i = 0; i < 2; i++)
          for (int j = 0; j < s[i].length(); j++)
            if (isalpha(s[i][j]))
              ss[i] += s[i][j];
        if (ss[0] == ss[1]) {
          if (s[0] == s[1]) puts("SAME");
          else puts("SIMILAR");
        } else puts("DIFFERENT");
        s[0] = s[1] = "";
        sc = 0;
      }
    } else s[sc] += c;
	return 0;
}
