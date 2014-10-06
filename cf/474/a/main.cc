#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+10;

char* keyboard[] = {
  " qwertyuiop ",
  " asdfghjkl; ",
  " zxcvbnm,./ "
};

int Find(int c, int shift)
{
  for (int i = 0; i < 3; i++)
    for (int j = 1; keyboard[i][j] != ' '; j++)
      if (keyboard[i][j+shift] == c)
        return keyboard[i][j];
  return 0;
}

char foo[N];

int main()
{
  int shift = 1;
  scanf("%s", foo);
  if (foo[0] == 'L')
    shift = -1;

  scanf("%s", foo);
  for (int i = 0; foo[i]; i++)
    foo[i] = Find(foo[i], shift);
  puts(foo);
  return 0;
}
