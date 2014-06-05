#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (20000)

struct BN
{
    vector<int> n;

    void ini()
    {
        n.clear();
        n.push_back(1);
    }

    void operator *= (int d)
    {
        Rep(i, 0, n.size()) n[i] *= d;
        Rep(i, 0, n.size() - 1)
        {
            n[i + 1] += n[i] / 10;
            n[i] %= 10;
        }
        while (n[n.size() - 1] > 9)
        {
            n.push_back(n[n.size() - 1] / 10);
            n[n.size() - 2] %= 10;
        }
    }

    void out()
    {
        Rep(i, 0, n.size())
            printf("%d", n[n.size() - 1 - i]);
    }
} zkl;

bool hpr[MAXN];
int cpr[MAXN];
vector<int> pri;

void PG()
{
    int i, j;

    pri.clear();
    pri.push_back(2);
    for (i = 4; i < MAXN; i += 2)
        hpr[i] = 1;
    for (i = 3; i < MAXN; i += 2)
        if (!hpr[i])
        {
            pri.push_back(i);
            for (j = i * i; j < MAXN; j += i)
                hpr[j] = 1;
        }
    #if 0
        Rep(i, 0, pri.size()) printf(" %d", pri[i]);
        putchar('\n');
    #endif
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, n, r, tmax;

    PG();
    scanf("%d", &T);
    Rep(C, 0, T)
    {
        Clr(cpr, MAXN, 0);
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &r);
            Rep(i, 0, pri.size())
            {
                if (r == 1) break;
                tmax = 0;
                while (r % pri[i] == 0)
                {
                    r /= pri[i];
                    tmax++;
                }
                if (tmax > cpr[pri[i]])
                    cpr[pri[i]] = tmax;
            }
        }
        #if 0
            Rep(i, 2, 10) printf("%3d", cpr[i]);
            putchar('\n');
        #endif
        zkl.ini();
        Rep(i, 2, MAXN)
            Rep(j, 0, cpr[i])
                zkl *= i;
        printf("Case %d: ", C + 1);
        zkl.out();
        putchar('\n');
    }

    return 0;
}
