#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (40)

char ch;
char e[MAXN] = "ertyuiop[]asdfghjkl;'zxcvbnm,./qw ";
char d[MAXN] = "qwertyuiop[]asdfghjkl;'zxcvbnm,./ ";

char sea(char ch)
{
    Rep(i, 0, MAXN)
    if (ch == e[i] || ch + 32 == e[i])
    return d[i];
}

int main()
{
    #if 0
        freopen("test.txt", "rt", stdin);
    #endif

    while (ch = getchar(), ch != EOF)
        putchar(sea(ch));

    return 0;
}
