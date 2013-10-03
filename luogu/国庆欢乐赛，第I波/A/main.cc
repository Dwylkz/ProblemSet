#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

char buff[N], op[3][N];

int main() {
#if 1
  stdin = fopen("input.in", "r");
#endif
  for ( ; fgets(buff, N, stdin); ) {
    int j = 0;
    for (char *i = strtok(buff, " +="); i; i = strtok(0, " +="))
      strcpy(op[j++], i);
    int a, b;
    if (*op[0] == '?') {
      sscanf(op[1], "%d", &a);
      sscanf(op[2], "%d", &b);
      printf("%d\n", b-a);
    } else if (*op[1] == '?') {
      sscanf(op[0], "%d", &a);
      sscanf(op[2], "%d", &b);
      printf("%d\n", b-a);
    } else {
      sscanf(op[0], "%d", &a);
      sscanf(op[1], "%d", &b);
      printf("%d\n", a+b);
    }
  }
  return 0;
}
