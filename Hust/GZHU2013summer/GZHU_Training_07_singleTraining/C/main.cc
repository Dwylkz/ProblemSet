#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  time_t stamp;
  tm* timeStruct;

  while(~scanf("%ld", &stamp))
  {
    timeStruct = gmtime(&stamp);
    printf("%s\n", asctime(timeStruct));

    printf("%.4d-%.2d-%.2d %.2d:%.2d:%.2d\n",
        timeStruct->tm_year + 1900,
        timeStruct->tm_mon + 1,
        timeStruct->tm_mday,

        timeStruct->tm_hour,
        timeStruct->tm_min,
        timeStruct->tm_sec
        );
  }
     
  return 0;
}
