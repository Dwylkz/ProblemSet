#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)

char tg[10][10] = {"Jia", "Yi", "Bing", "Ding", "Wu", "Ji", "Geng", "Xin", "Ren", "Gui"};
char dz[12][10] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T, y, t = 7, d = 11, tt, dd, det;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &y);
        det = y - 1911;
        if (y < 0) det++;
        tt = ((t + det) % 10 + 10) %10;
        dd = ((d + det) % 12 + 12) %12;
        printf("%s%s\n", tg[tt], dz[dd]);
    }

    return 0;
}
