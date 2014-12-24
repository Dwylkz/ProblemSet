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

const int N = 10+5;

typedef pair<string, string> PSS;
typedef map<string, PSS> MPss;

MPss lang;
char word[N];
int n, m;

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%s", word);
    string a = word;
    scanf("%s", word);
    string b = word;
    lang[a] = PSS(a, b);
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", word);
    string a = word;
    if (lang[a].first.size() <= lang[a].second.size())
      printf("%s", lang[a].first.data());
    else
      printf("%s", lang[a].second.data());
    putchar((i < n-1)? ' ': '\n');
  }
  return 0;
}
