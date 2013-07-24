#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
char buf[maxn], buf2[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	for ( ; ~scanf("%s\n", buf); ) {
    int l = strlen(buf), mx = atoi(buf);

    strcpy(buf2, buf);
    if (l) {
      buf2[l - 1] = 0;
    }
    mx = max(mx, atoi(buf2));
    strcpy(buf2, buf);
    if (1 < l && isdigit(buf2[l - 2])) {
      buf2[l - 2] = buf2[l - 1];
      buf2[l - 1] = 0;
    }
    mx = max(mx, atoi(buf2));
    printf("%d\n", mx);
	} 
	return 0;
}
