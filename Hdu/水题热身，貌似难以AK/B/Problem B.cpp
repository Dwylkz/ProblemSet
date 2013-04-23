#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define MAXN (32)
#define MAXL (6)
#define INFI (10000)
#define X2(x) (x * x)

int SG[MAXN][MAXL][MAXL][MAXL][MAXL][MAXL][MAXL];

void SG_ini()
{
    bool mex[MAXN << 2];
    int i[7];

    //memset(SG, 0, sizeof SG);
    for (i[1] = 0; i[1] <= 4; i[1]++)
        for (i[2] = 0; i[2] <= 4; i[2]++)
            for (i[3] = 0; i[3] <= 4; i[3]++)
                for (i[4] = 0; i[4] <= 4; i[4]++)
                    for (i[5] = 0; i[5] <= 4; i[5]++)
                        for (i[6] = 0; i[6] <= 4; i[6]++)
                            SG[0][i[1]][i[2]][i[3]][i[4]][i[5]][i[6]] = 0;
    Rep(rem, 1, 32)
        for (i[1] = 0; i[1] <= 4; i[1]++)
            for (i[2] = 0; i[2] <= 4; i[2]++)
                for (i[3] = 0; i[3] <= 4; i[3]++)
                    for (i[4] = 0; i[4] <= 4; i[4]++)
                        for (i[5] = 0; i[5] <= 4; i[5]++)
                            for (i[6] = 0; i[6] <= 4; i[6]++)
                            {
                                memset(mex, 0, sizeof mex);
                                Rep(j, 1, 7) if (i[j] && rem >= j)
                                {
                                    i[j]--;
                                    mex[SG[rem - j][i[1]][i[2]][i[3]][i[4]][i[5]][i[6]]] = 1;
                                    i[j]++;
                                }
                                /*if (i[1]) mex[SG[rem][i[1] - 1][i[2]][i[3]][i[4]][i[5]][i[6]]] = 1;
                                if (i[2]) mex[SG[rem][i[1]][i[2] - 1][i[3]][i[4]][i[5]][i[6]]] = 1;
                                if (i[3]) mex[SG[rem][i[1]][i[2]][i[3] - 1][i[4]][i[5]][i[6]]] = 1;
                                if (i[4]) mex[SG[rem][i[1]][i[2]][i[3]][i[4] - 1][i[5]][i[6]]] = 1;
                                if (i[5]) mex[SG[rem][i[1]][i[2]][i[3]][i[4]][i[5] - 1][i[6]]] = 1;
                                if (i[6]) mex[SG[rem][i[1]][i[2]][i[3]][i[4]][i[5]][i[6] - 1]] = 1;*/
                                Rep(j, 0, MAXN << 2) if (!mex[j])
                                {
                                    SG[rem][i[1]][i[2]][i[3]][i[4]][i[5]][i[6]] = j;
                                    break;
                                }
                            }
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    char ch[MAXN << 1];

    SG_ini();
    while (~scanf("%s", ch))
    {
        int l = strlen(ch), rem = 31, AB = 0, C[7];

        memset(C, 0, sizeof C);
        Rep(i, 0, l)
        {
            rem -= ch[i] - '0';
            C[ch[i] - '0']++;
            AB ^= 1;
        }
        Rep(i ,1, 7) C[i] = 4 - C[i];
#if 0
        printf("SG[%d][%d][%d][%d][%d][%d][%d] = %d\n",
               rem, C[1], C[2], C[3], C[4], C[5], C[6],
               SG[rem][C[1]][C[2]][C[3]][C[4]][C[5]][C[6]]);
#endif
        if (!SG[rem][C[1]][C[2]][C[3]][C[4]][C[5]][C[6]]) AB ^= 1;
        printf("%s %c\n", ch, AB + 'A');
    }

    return 0;
}
