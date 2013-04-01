#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (5500)

vector<string> s[6];

void Gen(string ts, int h)
{
    if (ts.length() == 5) return ;
    Rep(i, h, 26)
    {
        string tts = ts + char('a' + i);
        //puts(tts.c_str());
        s[tts.length()].push_back(tts);
        Gen(tts, i + 1);
    }
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T;
    char buf[MAXN];

    Gen("", 0);
    //Rep(i, 0, s[1].size()) printf("%s\n", s[1][i].c_str());
    while (~scanf("%s", buf))
    {
        bool bre = 0;
        int tsu = 1, l = strlen(buf);
        Rep(i, 1, l) if (buf[i] <= buf[i - 1])
        {
            bre = 1;
            break;
        }
        if (bre)
        {
            puts("0");
            continue;
        }
        Rep(i, 0, l) tsu += s[i].size();
        Rep(i, 0, s[l].size()) if (s[l][i] == buf)
        {
            tsu += i;
            break;
        }
        printf("%d\n", tsu);
    }

    return 0;
}
