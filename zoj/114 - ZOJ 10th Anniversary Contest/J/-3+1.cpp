#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define LLU long long

int n, a, b, c;
LLU ans;

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif
    int t;

    while (~scanf("%d", &n))
    {
        a = b = c = ans = 0;
        while (n--)
        {
            scanf("%d", &t);
            if (t < 3)
            {
                if (t == 1) a++;
                if (t == 2) b++;
            }
            else
            {
                while (t > 2)
                {
                    ans++;
                    t -= 2;
                    /*ans += t / 3;
                    t = t % 3 + t / 3;*/
                }
                c++;
                if (t > 1) a++;
            }
        }
        while (c && b)
        {
            ans++;
            b--;
        }
        while (c > 1 && a)
        {
            ans++;
            a--;
            c--;
        }
        while (c > 2)
        {
            ans++;
            c -= 2;
            /*ans += c / 3;
            c = c % 3 + c / 3;*/
        }

        printf("%lld\n", ans);
    }

    return 0;
}
