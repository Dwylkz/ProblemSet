#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (200)

vector<char> C;
map<char, char> M;
int n;
char ch[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    M['('] = ')';
    M['['] = ']';
    M['{'] = '}';
    while (~scanf("%d", &n))
    {
        C.clear();
        scanf("%s", ch);
        Rep(i, 0, n)
            if (ch[i] == '(' || ch[i] == '[' || ch[i] == '{')
                C.push_back(ch[i]);
            else if (C.size() && M[C[C.size() - 1]] == ch[i])
                C.pop_back();
            else if (!C.size())
            {
                C.push_back('.');
                break;
            }
        puts(C.size()?"NO": "YES");
    }

    return 0;
}
