#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (100)
typedef long long LL;

int n;

bool DFS(string &e, int dep)
{
    string et = "", ce = "", ms = "";
    while (n && n--)
    {
        char buf[MAXN];
        scanf("\n%[^\n]", buf);
        #if 1
            printf("n = %d\n", n);
            printf("%s\n", buf);
        #endif
        int op, l = strlen(buf);
        string s = "";
        Rep(i, 0, l) if (buf[i] != ' ')
        {
            s += buf[i];
            if (s.length() == 3 && s == "try")
            {
                op = 0;
                break;
            }
            if (s.length() == 5)
            {
                if (s == "throw")
                {
                    op = 1;
                    while (i < l && buf[i] != '(') i++;
                    i++;
                    for (;i < l && buf[i] != ')'; i++)
                        if (buf[i] != ' ') e += buf[i];
                    break;
                }
                if (s == "catch")
                {
                    op = 2;
                    while (i < l && buf[i] != '(') i++;
                    i++;
                    for (;i < l && buf[i] != ','; i++)
                        if (buf[i] != ' ') ce += buf[i];
                    while (i < l && buf[i] != '"') i++;
                    i++;
                    for (;i < l && buf[i] != '"'; i++)
                        ms += buf[i];
                    break;
                }
            }
        }
        printf("dep = %d et = %s ce = %s ms = %s\n", dep, et.c_str(), ce.c_str(), ms.c_str());
        if (op == 0 && DFS(et, dep + 1)) return 1;
        if (op == 2)
        {
            if (ce == et || ce == e) printf("%s\n", ms.c_str());
            return 1;
        }
        et = e;
    }
    return 0;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, Cas = 1;

    while (~scanf("%d", &n))
    {
        string et = "";
        if (!DFS(et, 0)) puts("Unhandled Exception");
    }

    return 0;
}
