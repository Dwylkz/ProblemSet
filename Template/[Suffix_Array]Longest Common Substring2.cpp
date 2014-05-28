#include<iostream>
#include<string>
using namespace std;
#define MAXI 200011

char str[MAXI];
int *sa = new int [MAXI];
int *tsa = new int [MAXI];
int *rank = new int [MAXI];
int *k1 = new int [MAXI];
int *k2 = new int [MAXI];
int *t, l, hash[MAXI], height[MAXI];

void CSA()
{
	int i, j, k, sigm = MAXI;
	for (i = 0; i < sigm; i++) hash[i] = 0;
	for (i = 0; i < l; i++) hash[k1[i] = str[i]]++;
	for (i = 1; i < sigm; i++) hash[i] += hash[i - 1];
	for (i = l - 1; i >= 0; i--) sa[--hash[str[i]]] = i;
	for (j = 1; j < l; j <<= 1, sigm++)
	{
		for (k = 0, i = l - j; i < l; i++) tsa[k++] = i;
		for (i = 0; i < l; i++)  if (sa[i] >= j) tsa[k++] = sa[i] - j;
		for (i = 0; i < l; i++) k2[i] = k1[sa[i]];
		for (swap(sa, tsa), i = 0; i < sigm; i++) hash[i] = 0;
		for (i = 0; i < l; i++) hash[k1[sa[i]]]++;
		for (i = 1; i < sigm; i++) hash[i] += hash[i - 1];
		for (i = l - 1; i >= 0; i--) tsa[--hash[k1[sa[i]]]] = sa[i];
		swap(sa, tsa); swap(k1, k2);
		for (sigm = k1[sa[0]] = 0, i = 1; i < l; i++)
			if (k2[sa[i]] == k2[sa[i - 1]] && k2[sa[i] + j] == k2[sa[i - 1] + j])
				k1[sa[i]] = sigm;
			else k1[sa[i]] = ++sigm;
	}
	for (i = 0; i < l; i++) rank[sa[i]] = i;
}

void CHA()
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

int main()
{
    int i, l1, l2, maxi;
    char tbuf[MAXI];

    while (scanf("%s", tbuf) != EOF)
    {
        l1 = strlen(tbuf);
        for (i = l = 0; i < l1; i++) str[l++] = tbuf[i];
        str[l++] = '#';
        scanf("%s", tbuf);
        l2 = strlen(tbuf);
        for (i = 0; i < l2; i++) str[l++] = tbuf[i];
        str[l++] = 0;
        CSA(), CHA();
        for (maxi = 0, i = 1; i < l; i++)
            if ((sa[i] < l1 && sa[i - 1] > l1) || (sa[i - 1] < l1 && sa[i] > l1))
                if (height[i] > maxi) maxi = height[i];
        printf("%d\n", maxi);
    }

    return 0;
}