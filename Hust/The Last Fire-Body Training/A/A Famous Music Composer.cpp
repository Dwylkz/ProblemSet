#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (10)

char key[MAXN], scale[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Cas = 1;

    while (~scanf("%s%s", key, scale))
    {
        printf("Case %d: ", Cas++);
        if (strlen(key) < 2) puts("UNIQUE");
        else
        {
            if (!strcmp(key, "C#")) printf("Db");
            if (!strcmp(key, "Db")) printf("C#");
            if (!strcmp(key, "D#")) printf("Eb");
            if (!strcmp(key, "Eb")) printf("D#");
            if (!strcmp(key, "F#")) printf("Gb");
            if (!strcmp(key, "Gb")) printf("F#");
            if (!strcmp(key, "G#")) printf("Ab");
            if (!strcmp(key, "Ab")) printf("G#");
            if (!strcmp(key, "A#")) printf("Bb");
            if (!strcmp(key, "Bb")) printf("A#");
            printf(" %s\n", scale);
        }
    }

    return 0;
}
