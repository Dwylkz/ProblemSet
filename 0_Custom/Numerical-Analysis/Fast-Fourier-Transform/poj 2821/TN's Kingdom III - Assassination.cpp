#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <complex>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (0x40000)
#define pi acos(-1.0)
typedef complex<double> Complex;

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
        Complex wn(cos(on * 2 * pi / m), sin(on * 2 * pi / m));

        for (j = 0; j < l; j += m)
        {
            Complex w(1, 0);
            for (k = j; k < j + m / 2; k++)
            {
                u = y[k];
                t = w * y[k + m / 2];
                y[k] = u + t;
                y[k + m / 2] = u - t;
                w *= wn;
            }
        }
    }
    if (on == -1.0) for (i = 0; i < l; i++) y[i] /= l;
}

int n;
Complex a[MAXN], b[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int bl = 1;
    double fbu;

    scanf("%d", &n);
    Rep(i, 0, n)
    {
        scanf("%lf", &fbu);
        a[i] = Complex(fbu, 0.0);
    }
    Rep(i, 0, n)
    {
        scanf("%lf", &fbu);
        b[i] = Complex(fbu, 0.0);
    }
    while (bl < 2 * n) bl <<= 1;
    Rep(i, n, bl) a[i] = b[i] = Complex(0.0, 0.0);
    FFT(a, bl, 1.0);
    FFT(b, bl, 1.0);
    Rep(i, 0, bl) a[i] = b[i] / a[i];
    FFT(a, bl, -1.0);
    Rep(i, 0, n) printf("%.4lf\n", a[i].real());

    return 0;
}
