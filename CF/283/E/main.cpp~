#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXB = 44;
const int MAXN = 10e5 + 5;
typedef long long LL;

typedef struct node {
	node *s[2];
} *pnode;
pnode top, root;
struct trie {
	void init() 
	{
		root = create();
	}
	pnode create()
	{
		pnode x = new node;
		x->s[0] = x->s[1] = 0;
		return x;
	}
	void insert (LL k) 
	{
		pnode x = root;
		for (int i = MAXB - 1; -1 < i; i--) {
			bool b = (k >> i) & 1;
			if (!x->s[b]) {
				x->s[b] = create();
			}
			x = x->s[b];
		}
	}
	LL search_max(LL k)
	{
		LL result = 0;
		pnode x = root;
		for (int i = MAXB - 1; -1 < i; i--) {
			bool b = (k >> i) & 1;
			if (x->s[!b]) {
				result += 1LL << i;
				x = x->s[!b];
			}
			else {
				x = x->s[b];
			}
		}
		return result;
	}
};

int n;
LL s[MAXN];
trie zkl;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%lld", s + i);
		}
		s[0] = s[n + 1] = 0;
		n = n + 2;
		LL tsu = 0;
		zkl.init();
		for (int i = 0; i < n; i++) {
			tsu ^= s[i];
			zkl.insert(tsu);
		}
		LL result = 0;
		tsu = 0;
		for (int i = n - 1; -1 < i; i--) {
			tsu ^= s[i];
			result = max(result, zkl.search_max(tsu));
		}
		printf("%lld\n", result);
	}
	return 0;
}
