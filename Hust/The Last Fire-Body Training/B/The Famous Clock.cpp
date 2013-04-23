#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (10)

char num[MAXN];

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int Cas = 1;

    while (~scanf("%s", num))
    {
        printf("Case %d: ", Cas++);
        if (!strcmp(num, "I")) puts("1");
        if (!strcmp(num, "II")) puts("2");
        if (!strcmp(num, "III")) puts("3");
        if (!strcmp(num, "IV")) puts("4");
        if (!strcmp(num, "V")) puts("5");
        if (!strcmp(num, "VI")) puts("6");
        if (!strcmp(num, "VII")) puts("7");
        if (!strcmp(num, "VIII")) puts("8");
        if (!strcmp(num, "IX")) puts("9");
        if (!strcmp(num, "X")) puts("10");
        if (!strcmp(num, "XI")) puts("11");
        if (!strcmp(num, "XII")) puts("12");
    }

    return 0;
}
