#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <complex>
using namespace std;
#define MAXN (220000)
#define pi acos(-1.0)
#define Complex complex<double>

Complex op1[MAXN], op2[MAXN];

char a[MAXN],b[MAXN];
int sum[MAXN];

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
        Complex wn(cos(on * 2 * pi / m),sin(on * 2 * pi / m));

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

int main()
{
    #if 0
        freopen("test.txt", "rt", stdin);
    #endif

    int l1, l2, i, l;

    while (scanf("%s %s",a,b) != EOF)
    {
        l1 = strlen(a);
        l2 = strlen(b);
        l = 1;
        while (l < l1 * 2 || l < l2 * 2) l <<= 1;
        for (i = 0; i < l1; i++)
            op1[i] = Complex(a[l1 - i - 1] - '0', 0.0);
        for (; i<l; i++) op1[i] = Complex(0.0, 0.0);
        for (i = 0;i < l2; i++)
            op2[i] = Complex(b[l2 - i - 1] - '0', 0.0);
        for (; i<l; i++) op2[i] = Complex(0.0, 0.0);
        FFT(op1, l, 1);
        FFT(op2, l, 1);
        for (i = 0; i < l; i++) op1[i] = op1[i] * op2[i];
        FFT(op1, l, -1);
        for (i = 0 ; i < l; i++) sum[i] = op1[i].real() + 0.5;
        for (i = 0; i < l; i++)
        {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        l = l1 + l2 - 1;
        while (sum[l] <= 0 && l > 0) l--;
        for (i = l; i>=0; i--) printf("%d", sum[i]);
        printf("\n");
    }
    return 0;
}
