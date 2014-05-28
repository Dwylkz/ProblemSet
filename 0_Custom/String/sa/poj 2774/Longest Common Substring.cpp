#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (220000)
#define INFI (512)

struct SA
{
    int S[2][MAXN], rank[MAXN], K[2][MAXN];
    int *sa, *ts, *k1, *k2;
    int l, hash[MAXN], height[MAXN];
    void ini(char * str)
    {
        CSA(str);
        CHA(str);
    }

    void CSA(char *str)
    {
        int i, j, k, sigm = MAXN;
        l = strlen(str);
        sa = S[0]; ts = S[1]; k1 = K[0]; k2 = K[1];
        for (i = 0; i < sigm; i++) hash[i] = 0;
        for (i = 0; i < l; i++) hash[k1[i] = str[i]]++;
        for (i = 1; i < sigm; i++) hash[i] += hash[i - 1];
        for (i = l - 1; i >= 0; i--) sa[--hash[str[i]]] = i;
        for (j = 1; j < l; j <<= 1, sigm++)
        {
            for (k = 0, i = l - j; i < l; i++) ts[k++] = i;
            for (i = 0; i < l; i++)  if (sa[i] >= j) ts[k++] = sa[i] - j;
            for (i = 0; i < l; i++) k2[i] = k1[sa[i]];
            for (swap(sa, ts), i = 0; i < sigm; i++) hash[i] = 0;
            for (i = 0; i < l; i++) hash[k1[sa[i]]]++;
            for (i = 1; i < sigm; i++) hash[i] += hash[i - 1];
            for (i = l - 1; i >= 0; i--) ts[--hash[k1[sa[i]]]] = sa[i];
            swap(sa, ts); swap(k1, k2);
            for (sigm = k1[sa[0]] = 0, i = 1; i < l; i++)
                if (k2[sa[i]] == k2[sa[i - 1]] && k2[sa[i] + j] == k2[sa[i - 1] + j])
                    k1[sa[i]] = sigm;
                else k1[sa[i]] = ++sigm;
        }
        for (i = 0; i < l; i++) rank[sa[i]] = i;
    }

    void CHA(char *str)
    {
        int i, add;
        for (i = 0; i < l; i++)
            if (rank[i] == 0) height[rank[i]] = 0;
            else
            {
                if (i == 0 || height[rank[i - 1]] <= 1) add = 0;
                else add = height[rank[i - 1]] - 1;
                while (str[sa[rank[i]] + add] == str[sa[rank[i] - 1] + add]) add++;
                height[rank[i]] = add;
            }
    }
} zkl;

char A[MAXN], B[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int la, lb, maxi;

    while (~scanf("%s", A))
    {
        scanf("%s", B);
        la = strlen(A);
        lb = strlen(B);

        A[la] = '#';
        Rep(i, la + 1, la + 1 + lb)
            A[i] = B[i - la - 1];
        A[la + 1 + lb] = '$';
        A[la + lb + 2] = '\0';
        zkl.ini(A);
        maxi = 0;
        Rep(i, 1, la + lb + 2)
            if ((zkl.sa[i] < la && zkl.sa[i - 1] > la) || (zkl.sa[i - 1] < la && zkl.sa[i] > la))
                if (zkl.height[i] > maxi) maxi = zkl.height[i];
        printf("%d\n", maxi);
    }

    return 0;
}
