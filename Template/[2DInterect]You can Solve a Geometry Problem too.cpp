#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define fmax(x, y) ((x) > (y)? (x): (y))
#define fmin(x, y) ((x) < (y)? (x): (y))
#define MAXI 101

class vec
{
public :
    double x, y;
    vec(double tx = 0.0, double ty = 0.0)
    {
        x = tx;
        y = ty;
    }
};

class seg
{
public :
    vec a, b;
    double A, B, C;
    seg(vec ta = vec(0.0, 0.0), vec tb = vec(0.0, 0.0))
    {
        a = ta;
        b = tb;
    }
    void ABC()
    {
        A = b.y - a.y;
        B = a.x - b.x;
        C = -(A * a.x + B * a.y);
    }
    bool ons(vec o)
    {
        if (fmin(a.x, b.x) <= o.x && o.x <= fmax(a.x, b.x))
            if (fmin(a.y, b.y) <= o.y && o.y <= fmax(a.y, b.y))
                return true;
        return false;
    }
    bool inr(seg o, double &x, double &y)
    {
        double d;
        ABC(); o.ABC();
        d = A * o.B - o.A * B;
        x = (B * o.C - o.B * C) / d;
        y = (A * o.C - o.A * C) / -d;
        if (ons(vec(x, y)) && o.ons(vec(x, y))) return true;
        return false;
    }
}s[MAXI];

int main()
{
    int i, j, n, tsu;
    double x, y;

    while (cin >> n, n)
    {
        tsu = 0;
        for (i = 0; i < n; i++)
        {
            cin >> s[i].a.x >> s[i].a.y >> s[i].b.x >> s[i].b.y;
            for (j = 0; j < i; j++)
                if (s[i].inr(s[j], x, y))
                    tsu++;
        }
        cout << tsu << endl;
    }
    return 0;
}
