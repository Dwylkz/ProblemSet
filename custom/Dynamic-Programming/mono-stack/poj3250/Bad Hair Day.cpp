#include<cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;
typedef unsigned long long LLU;

int n, c;
stack<int> S;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    LLU ans = 0;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &c);
        while (!S.empty() && S.top() <= c) S.pop();
        ans += S.size();
        S.push(c);
    }
    printf("%llu\n", ans);

    return 0;
}
