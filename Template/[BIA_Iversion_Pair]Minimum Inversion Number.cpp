#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class BIA
{
public :
    typedef int ty1;
    typedef int ty2;
    vector<ty2> tre;
    void ini(ty1 n)
    {
        tre.clear();
        tre.resize(n);
    }
    ty1 low(ty1 x)
    {
        return x & (-x);
    }
    void upd(ty1 x, ty2 add)
    {
        while (x < tre.size())
        {
            tre[x] += add;
            x += low(x);
        }
    }
    ty2 que(ty1 x)
    {
        ty2 tsu = 0;
        while (x > 0)
        {
            tsu += tre[x];
            x -= low(x);
        }
        return tsu;
    }
} zkl;

int main()
{
    int i, n, tsu, mini;
    vector<int> s;

    while (scanf("%d", &n) != EOF)
    {
        s.resize(n);
        zkl.ini(n + 1);
        for (tsu = i = 0; i < n; i++)
        {
            scanf("%d", &s[i]);
            zkl.upd(s[i] + 1, 1);
            tsu += zkl.que(n) - zkl.que(s[i] + 1);
        }
        mini = tsu;
        for (i = 0; i < n - 1; i++)
        {
            tsu -= 2 * s[i] - n + 1;
            if (tsu < mini) mini = tsu;
        }
        printf("%d\n", mini);
    }
    return 0;
}
