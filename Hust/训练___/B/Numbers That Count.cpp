#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN ()
#define MAXC (88)

string num;
map<string, int> H;

void pus(string &s, int n)
{
    if (!n) return ;
    pus(s, n / 10);
    s += n % 10 + '0';
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int ind, fin, fij, ha[MAXC];
    string ori, buf;

    while (cin >> num, num != "-1")
    {
        fin = 3;
        ori = num;
        ind = 1;
        H.clear();
        Rep(i, 0, 15)
        {
            H[num] = ind++;
            buf.clear();
            memset(ha, 0, sizeof ha);
            Rep(j, 0, num.length()) ha[num[j]]++;
            #if 0
                printf(" loop %d = %s\n", i, num.c_str());
                Rep(j, 0, MAXC) if (ha[j])
                    printf("%c : %d\n", j, ha[j]);
            #endif
            Rep(j, 0, MAXC) if (ha[j])
            {
                pus(buf, ha[j]);
                buf += j;
            }
            num = buf;
            if (H[num])
            {
                fij = ind - H[num];
                if (fij < 2)
                {
                    fin = bool(i);
                    fij = i;
                }
                else if (fij >= 2) fin = 2;
                break;
            }
        }
        #if 0
            printf(" len = %d\n", num.length());
        #endif
        printf("%s", ori.c_str());
        if (!fin) puts(" is self-inventorying");
        else if (fin < 2) printf(" is self-inventorying after %d steps\n", fij);
        else if (fin < 3) printf(" enters an inventory loop of length %d\n", fij);
        else puts(" can not be classified after 15 iterations");
    }

    return 0;
}
