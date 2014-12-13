#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int N = 1e6+5;

char s[N];

int main()
{
	while (~scanf("%s", s)) {
    const char* ans[] = {"No", "Yes"};
    int nq = 0, n = strlen(s);
    for (int i = 0; s[i]; i++)
      if (s[i] == 'Q')
        nq++;
    int q = sqrt(nq);
    if (q*q != nq) {
      puts(ans[0]);
      continue;
    }
    if (q == 0) {
      puts(ans[1]);
      continue;
    }
    string foo = "";
    int pre = 0, j = 0;
    while (j < q) {
      if (s[pre] == 'Q')
        j++;
      foo += s[pre++];
    }
    int first = foo.find('Q');
    foo.erase(foo.begin(), foo.begin()+first/2);
    int suf = n;
    while (s[suf-1] != 'Q')
      suf--;
    for (int i = suf+(n-suf)/2; s[i]; i++)
      foo += s[i];
    string bar;
    for (int i = 0; foo[i]; i++)
      if (foo[i] == 'H')
        bar += 'H';
      else
        bar += foo;
    puts(ans[!strcmp(s, bar.data())]);
	}
	return 0;
}
