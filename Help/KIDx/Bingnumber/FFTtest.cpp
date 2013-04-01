#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
//#include <map>
#include <queue>
#include <utility>
#include <iomanip>
#include <stack>
#include <list>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <complex>
using namespace std;
#define MAXN (220000)

typedef complex<double> Complex;
const double Pi = acos(-1.0);

//VC6貌似要#include <iostream.h>，而且using namespace std要注释掉;
class BigInteger{
public:
    BigInteger ()
    {
        for (int i = 0; i < MAXN; i++)
            str[i] = '0';
    }
    void display ()
    {
        printf ("%s\n", str);
    }
    char * operator = (char *s)
    {
        strcpy (str, s);
        len = strlen (s);
        return s;
    }
    friend void BRC(Complex *y, int l);
    friend void FFT(Complex *y, int l, double on);
    friend BigInteger operator * (BigInteger &a, BigInteger &b);
    char str[MAXN];    //一个大数的表示方式，对于这题，定得太大了……
    int len;    //一个大数的长度，即位数
};

void BRC(Complex *y, int l)
{
    int i, j, k;

    j = l >> 1;
    for (i = 1; i < l - 1; i++)
    {
        if (i < j) swap(y[i], y[j]);
        k = l >> 1;
        while (j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if (j < k) j += k;
    }
}

void FFT(Complex *y, int l, double on)
{
    int i, j, k, m;

    Complex u, t;
    BRC(y, l);
    for (m = 2; m <= l; m <<= 1)
    {
        Complex wn(cos(on * 2 * Pi / m),sin(on * 2 * Pi / m));

        for (j = 0; j < l; j += m)
        {
            Complex w(1, 0);
            for (k = j; k < j + m / 2; k++)
            {
                u = y[k];
                t = w * y[k + m / 2];
                y[k] = u + t;
                y[k + m / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1.0) for (i = 0; i < l; i++) y[i] /= l;
}

Complex x[MAXN], y[MAXN];
int sum[MAXN];

BigInteger operator * (BigInteger &a, BigInteger &b)
{
    BigInteger res;
    Complex x[4020], y[4020];
    int i, j, l = 1;

    //增长翻转换虚数补零
    while (l < a.len * 2 || l < b.len * 2) l <<= 1;
    for (i = 0; i < a.len; i++)
        x[i] = Complex(a.str[a.len - i - 1] - '0', 0);
    while (i < l) x[i++] = Complex(0, 0);
    for (i = 0; i < b.len; i++)
        y[i] = Complex(b.str[b.len - i - 1] - '0', 0);
    while (i < l) y[i++] = Complex(0, 0);
    //FFT
    FFT(x, l, 1);
    FFT(y, l, 1);
    for (i = 0; i < l; i++) x[i] *= y[i];
    FFT(x, l, -1);
    //转Bignumber进位
    for (i = 0; i < l; i++) sum[i] = x[i].real() + 0.5;
    for (i = 0; i < l - 1; i++)
    {
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }
    while (!sum[l - 1] && l > 1) l--;
    res.len = l;
    for (i = 0; i < l; i++) res.str[i] = sum[i] + '0';
    for (i = 0; i < l / 2; i++)
        swap(res.str[i], res.str[l - i - 1]);
    res.str[l] = 0;

    return res;
}

BigInteger a, b;
char buf[MAXN];

int main()
{
    while (~scanf("%s", buf))
    {
        a = buf;
        scanf("%s", buf);
        b = buf;
        (a * b).display();
    }

    return 0;
}
