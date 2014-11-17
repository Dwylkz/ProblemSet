#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 1e1+5;

char lcd[5][10][4] = {
  {" - ", "   ", " - ", " - ", "   ", " - ", " - ", " - ", " - ", " - "},
  {"| |", "  |", "  |", "  |", "| |", "|  ", "|  ", "  |", "| |", "| |"},
  {"   ", "   ", " - ", " - ", " - ", " - ", " - ", "   ", " - ", " - "},
  {"| |", "  |", "|  ", "  |", "  |", "  |", "| |", "  |", "| |", "  |"},
  {" - ", "   ", " - ", " - ", "   ", " - ", " - ", "   ", " - ", " - "}
};

int s;
char n[N];

void HScale(int r)
{
  for (int i = 0; n[i]; i++) {
    int d = n[i]-'0';
    putchar(lcd[r][d][0]);
    for (int k = 0; k < s; k++)
      putchar(lcd[r][d][1]);
    putchar(lcd[r][d][2]);
    if (!n[i+1])
      putchar('\n');
    else
      putchar(' ');
  }
}

void VScale(int r)
{
  for (int k = 0; k < s; k++)
    HScale(r);
}

int main()
{
  while (~scanf("%d%s", &s, n) && !(s == 0 && !n[1] && n[0] == '0')) {
    for (int i = 0; i < 5; i++)
      if (i%2)
        VScale(i);
      else
        HScale(i);
    putchar('\n');
  }
  return 0;
}
