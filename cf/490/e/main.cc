#include <sstream>
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
const int M = 8+5;

int n;
char d[N][M];

void MinRepair(char* head)
{
  for (char* i = head+1; *i; i++)
    if (*i == '?')
      *i = '0';
  if (*head == '?')
    *head = '1';
}

bool EqualRepair(char* lhs, char* rhs)
{
  string minv = "#";
  for (int i = 0; rhs[i]; i++) {
    if (!(lhs[i] < rhs[i] || rhs[i] == '?'))
      continue;
    string t = rhs;
    if (t[i] == '?')
      t[i] = min(lhs[i]+1, '9'+0);
    for (int j = 0; j < i; j++)
      if (t[j] == '?')
        t[j] = lhs[j];
    for (int j = i+1; t[j]; j++)
      if (t[j] == '?')
        t[j] = '0';
    if (string(lhs) < t && (minv == "#" || minv > t))
      minv = t;
  }
  if (minv == "#")
    return false;
  strcpy(rhs, minv.data());
  return true;
}

bool IsOk(char* lhs, char* rhs)
{
  int d = strlen(lhs)-strlen(rhs);
  if (d > 0)
    return false;
  if (d < 0) {
    MinRepair(rhs);
    return true;
  }
  return EqualRepair(lhs, rhs);
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%s", d[i]);
  MinRepair(d[0]);
  for (int i = 1; i < n; i++)
    if (!IsOk(d[i-1], d[i])) {
      puts("NO");
      return 0;
    }
  puts("YES");
  for (int i = 0; i < n; i++)
    puts(d[i]);
  return 0;
}
