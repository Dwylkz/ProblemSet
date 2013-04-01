#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXM (1024)
#define MAXC (100)

vector<string> S;


int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Case, now;
    char op[MAXC], wb[MAXC];

    scanf("%d", &Case);
    Rep(CCas, 1, Case + 1)
    {
        now = 0;
        S.clear();
        S.push_back("http://www.lightoj.com/");
        printf("Case %d:\n", CCas);
        while (scanf("%s", op))
        {
            if (!strcmp(op, "QUIT")) break;
            if (!strcmp(op, "BACK"))
            {
                if (!now)
                {
                    puts("Ignored");
                    continue;
                }
                now--;
                printf("%s\n", S[now].c_str());
            }
            if (!strcmp(op, "FORWARD"))
            {
                if (now == S.size() - 1)
                {
                    puts("Ignored");
                    continue;
                }
                now++;
                printf("%s\n", S[now].c_str());
            }
            if (!strcmp(op, "VISIT"))
            {
                scanf("%s", wb);
                while (now < S.size() - 1) S.pop_back();
                S.push_back(wb);
                now++;
                printf("%s\n", wb);
            }
        }
    }

    return 0;
}
