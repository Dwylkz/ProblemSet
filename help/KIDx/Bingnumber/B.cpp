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
using namespace std;
//VC6貌似要#include <iostream.h>，而且using namespace std要注释掉;
class BigInteger{
public:
    BigInteger ()
    {
        for (int i = 0; i < 2010; i++)
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
    friend BigInteger operator + (BigInteger &a, BigInteger &b);
    friend BigInteger operator * (BigInteger &a, BigInteger &b);
	friend bool operator >= (BigInteger &a, BigInteger &b);
	friend bool operator <= (BigInteger &a, BigInteger &b);
    char str[2010];    //一个大数的表示方式，对于这题，定得太大了……
    int len;    //一个大数的长度，即位数
};

BigInteger operator + (BigInteger &a, BigInteger &b)
{
    BigInteger tp, ta, tb, res;
    int k = a.len > b.len ? a.len : b.len, w = 0, i;
    //翻转
    for (i = a.len - 1; i >= 0; i--)
        ta.str[w++] = a.str[i];
    ta.str[w] = 0;
    w = 0;
    for (i = b.len - 1; i >= 0; i--)
        tb.str[w++] = b.str[i];
    tb.str[w] = 0;
    w = 0;
    //按位相加
    for (i = 0; i < k; i++)
    {
        if (ta.str[i] == 0)
            ta.str[i] = '0';
        if (tb.str[i] == 0)
            tb.str[i] = '0';
        tp.str[i] = ((ta.str[i]-'0') + (tb.str[i]-'0') + w) + '0';
        w = 0;
        if (tp.str[i] > '9')
            tp.str[i] -= 10, w = 1;
    }
    if (w > 0)
        tp.str[k]++, k++;
    w = 0;
    for (i = k - 1; i >= 0; i--)
        res.str[w++] = tp.str[i];
    res.str[w] = 0;
    res.len = k;
    return res;
}

BigInteger operator * (BigInteger &a, BigInteger &b)
{
    BigInteger tp, ta, tb, res;
    int k = b.len + a.len, w = 0, i, j;
    //翻转
    for (w = 0, i = a.len - 1; i >= 0; i--)
        ta.str[w++] = a.str[i] - '0';
    ta.str[w] = 0;
    for (w = 0, i = b.len - 1; i >= 0; i--)
        tb.str[w++] = b.str[i] - '0';
    tb.str[w] = 0;
    //按位相加
    for (i = 0; i < k; i++) res.str[i] = 0;
    for (i = 0; i < a.len; i++)
        for (j = 0; j < b.len; j++)
        {
            res.str[i + j] += ta.str[i] * tb.str[j];
            res.str[i + j + 1] += res.str[i + j] / 10;
            res.str[i + j] %= 10;
        }
    while (!res.str[k - 1] && k > 1) k--;
    res.len = k;
    for (i = 0; i < k; i++) res.str[i] += '0';
    for (i = 0; i < k / 2; i++)
    {
        res.str[i] ^= res.str[k - i - 1];
        res.str[k - i - 1] ^= res.str[i];
        res.str[i] ^= res.str[k - i - 1];
    }
    return res;
}

bool operator >= (BigInteger &a, BigInteger &b)
{
	if (a.len > b.len)
		return true;
	if (a.len == b.len && strcmp (a.str, b.str) >= 0)
		return true;
	return false;
}

bool operator <= (BigInteger &a, BigInteger &b)
{
	if (a.len < b.len)
		return true;
	if (a.len == b.len && strcmp (a.str, b.str) <= 0)
		return true;
	return false;
}

BigInteger f[500], a, b;

int main()
{
    int i, map[110], start, end, res;
	char s[105], p[105];
    f[1] = "1";
	f[2] = "2";
	map[1] = 1;
    for (i = 3; i < 500; i++)
	{
		f[i] = f[i-1] + f[i-2];
		if (f[i].len == f[i-1].len)
			map[f[i].len] = map[f[i-1].len];    //长度映射到位置
		else map[f[i].len] = i;
	}
    while (scanf ("%s%s", s, p))
	{
		if (!strcmp (s, "0") && !strcmp (p, "0"))
			break;
		a = s, b = p;
		start = map[a.len];   //根据a、b的位数读取范围
		end = map[b.len+1];
		res = 0;
		for (i = start; i <= end; i++)//i是位置，相当于f[i]的i，是下标，范围只有500
			if (f[i] >= a && f[i] <= b)
				res++;
		printf ("%d\n", res);
	}
    return 0;
}
