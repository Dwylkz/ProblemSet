#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (40)
#define MAXC (256)

char na[MAXN], ha[MAXC];

void mta()
{
    int pos = 2;

    Rep(i, 0, 15)
    {
        if (i && i % 3 == 0)
            pos++;
        ha['a' + i] = ha['A' + i] = pos;
    }
    pos++;
    Rep(i, 15, 19)
        ha['a' + i] = ha['A' + i] = pos;
    pos++;
    Rep(i, 19, 22)
        ha['a' + i] = ha['A' + i] = pos;
    pos++;
    Rep(i, 22, 26)
        ha['a' + i] = ha['A' + i] = pos;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("test.txt", "rt", stdin);
	#endif

	int n, l;
	bool same;

    mta();
	scanf("%d", &n);
	while (n--)
	{
		same = 1;
		scanf("%s", na);
		l = strlen(na);
		Rep(i, 0, l / 2)
			if (ha[na[i]] != ha[na[l - i - 1]])
				same = 0;
        #if 0
            Rep(i, 0, l) printf("%d", ha[na[i]]);
            printf("\n");
        #endif
		puts(same? "YES": "NO");
	}

	return 0;
}
