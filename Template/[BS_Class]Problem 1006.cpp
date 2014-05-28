#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//Macro Begin
#define LLU int
#define Rep(c, a, b) for (LLU c = a; c < b; c++)
//Macro End.

class BSN
{
public :
    vector<LLU> num;
    void ini()
    {
        num.clear();
        num.push_back(1);
    }
    void operator *= (LLU o)
    {
        Rep(i, 0, num.size())
            num[i] *= o;
        Rep(i, 0, num.size() - 1)
        {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        while (num[num.size() - 1] > 9)
        {
            num.push_back(num[num.size() - 1] / 10);
            num[num.size() - 2] %= 10;
        }
    }
    void operator -= (BSN o)
    {
        int j;
        Rep(i, 0, o.num.size())
        {
            if (num[i] < o.num[i])
            {
                num[i] += 10;
                num[i + 1] -= 1;
            }
            num[i] -= o.num[i];
        }
        j = o.num.size();
        while (j < num.size() - 1 && num[j] < 0)
        {
            num[j] += 10;
            num[j + 1] -= 1;
        }
    }
    void operator /= (LLU o)
    {
        int i, div, mod, tp = 0;
        for (i = num.size() - 1; i >= 0; i--)
        {
            mod = (num[i] + tp) % o;
            num[i] = (num[i] + tp) / o;
            tp = mod * 10;
        }
        while (num.size() > 0 && num[num.size() - 1] == 0)
            num.pop_back();
    }
    LLU operator % (LLU o)
    {
        int i, tp = 0;
        for (i = num.size() - 1; i >= 0; i--)
            tp = (tp + num[i]) % o * 10;
        return tp / 10;
    }
    void oup()
    {
        Rep(i, 0, num.size())
            printf("%d", num[num.size() - i - 1]);
        putchar('\n');
    }
} ts1, ts2, ts3;

LLU n, m;

LLU GCD(LLU a, LLU b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

LLU BS_GCD(BSN o1, LLU o2)
{
    int i;
    for (i = o2; i > 0; i--)
        if (o1 % i == 0 && o2 % i == 0)
            return i;
}

LLU Calc(LLU a, LLU b)
{
    LLU tsu = 1;
    Rep(i, a, b + 1)
        tsu *= i;
    return tsu;
}

int main()
{
    LLU t1, t2, t3, gcd;
    vector <LLU> mo1, mo2, den;

    scanf("%d%d", &n, &m);
    mo1.clear();
    mo2.clear();
    den.clear();
    Rep(i, m, n + m)
        mo1.push_back(i);
    Rep(i, 1, n + 1)
        mo2.push_back(i);
    if (mo2.size() == 0)
        mo2.push_back(1);
    Rep(i, 1, n + m)
        den.push_back(i);
    den.push_back(m - 1);
    ts1.ini();
    ts2.ini();
    ts3.ini();
    Rep(i, 0, mo1.size())
        ts1 *= mo1[i];
    Rep(i, 0, mo2.size())
        ts2 *= mo2[i];
    if (mo2.size() == 0)
        ts2 *= 0;
    ts1 -= ts2;
    Rep(i, 0, den.size())
    {
        gcd = BS_GCD(ts1, den[i]);
        ts1 /= gcd;
        den[i] /= gcd;
        ts3 *= den[i];
    }
    ts1.oup();
    ts3.oup();

    return 0;
}
