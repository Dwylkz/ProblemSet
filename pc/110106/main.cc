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

const int N = 1e3+5;
const int M = 10+5;
const int B = 4+5;
const int MOD = 1e3;

int reg[M];
char ram[N][B];

int main()
{
  int kase;
  scanf("%d", &kase);
  gets(ram[0]);
  gets(ram[0]);
  for (int i = 0; i < kase; i++) {
    for (int i = 0; i < N; i++) {
      memset(ram[i], 0, sizeof(ram[i]));
      strcat(ram[i], "000");
    }
    int n = 0;
    while (gets(ram[n]) && strlen(ram[n]) > 0)
      n++;
    // for (int i = 0; i < n; i++)
    //   puts(ram[i]);
    int cnt = 0, pt = 0;
    memset(reg, 0, sizeof(reg));
    // for (int i = 0; i < 10; i++)
    //   printf("%03d ", i);
    // puts("");
    while (true) {
      cnt++;
      if (strcmp(ram[pt], "100") == 0)
        break;
      int np = pt+1;
      int x = ram[pt][1]-'0';
      int y = ram[pt][2]-'0';
      switch (ram[pt][0]) {
        case '2': {
          reg[x] = y;
          break;
        }
        case '3': {
          reg[x] = (reg[x]+y)%MOD;
          break;
        }
        case '4': {
          reg[x] = (reg[x]*y)%MOD;
          break;
        }
        case '5': {
          reg[x] = reg[y];
          break;
        }
        case '6': {
          reg[x] = (reg[x]+reg[y])%MOD;
          break;
        }
        case '7': {
          reg[x] = (reg[x]*reg[y])%MOD;
          break;
        }
        case '8': {
          sscanf(ram[reg[y]], "%d", reg+x);
          break;
        }
        case '9': {
          sprintf(ram[reg[y]], "%03d", reg[x]);
          break;
        }
        case '0': {
          // printf("d=%d, s=%d\n", reg[d], reg[s]);
          if (reg[y] != 0)
            np = reg[x];
          break;
        }
        default: {
        }
      }
      // puts(ram[pt]);
      // for (int i = 0; i < 10; i++)
      //   printf("%03d ", reg[i]);
      // puts("");
      pt = np;
    }
    if (i > 0)
      puts("");
    printf("%d\n", cnt);
  }
  return 0;
}
