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

const int N = 1e5+5;

int n;
char s[N];

int main()
{
  scanf("%s", s);
  vector<char> st;
  for (int i = 0; s[i]; i++)
    if (st.size() > 0 && st.back() == s[i])
      st.pop_back();
    else
      st.push_back(s[i]);
  if (st.size() > 0)
    puts("No");
  else
    puts("Yes");
  return 0;
}
