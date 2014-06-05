//coder: SXDwylkz
//heads
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
	  output[] = "input.in";
const int inf32 = 0x7fffffff,
	  maxn = 1e5+10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//AC Automaton
//include: queue, cstring
//usage: obj.Init->obj.Link->(obj.$(others))*
struct ACA {
	const static int n = maxn,  //Total of nodes
		  m = 127,               //Size of charator set
		  shift = 0;          //Charactor shift
	struct Node {
		//Extern
		//Basic
		Node *s[m],             //Adjust node
			 *p;                //Failure link
		int  a;                 //Accpet state or not
	};
	typedef Node *PNode;
	Node t[n];                  //Storage pool
	PNode top,                  //t's iterator
		  rt;                   //Initial State
	//Init a node
	//usage: obj.New([length], [Failure Link])
	PNode New() {
		memset(top, 0, sizeof(Node));
		return top++;
	}
	//Init
	//usage: obj.Init()
	void Init() {
		top = t;
		rt = New();
	}
	//Append a string
	//usage: obj.Insert(charactor)
	void Insert(int a, char *s, int sl) {
		PNode x = rt;
		for (int i = 0; i < sl; i++) {
			int k = s[i] - shift;
			if (!x->s[k]) {
				x->s[k] = New();
			}
			x = x->s[k];
		}
		x->a = a;
	}
	//Failure Linking
	//usage: obj.Link()
	void Link() {
		static PNode Q[n];
		Q[0] = rt;
		for (int f = 0, t = 1; f < t; ) {
			PNode x = Q[f++];
			for (int i = 0; i < m; i++) {
				if (x->s[i]) {
					if (x == rt) {
						x->s[i]->p = x;
					} else {
						PNode y = x->p;
						for (; y && !y->s[i]; y = y->p) {
						}
						if (!y) {
							x->s[i]->p = rt;
						} else {
							x->s[i]->p = y->s[i];
						}
					}
					Q[t++] = x->s[i];
				}
			}
		}
	}
	int Search(int a, char *s, int sl) {
		int total = 0, r[500], rl = 0;
		PNode x = rt;
		for (int i = 0; i < sl; i++) {
			int k = s[i] - shift;
			for ( ; x && !x->s[k]; x = x->p) {
			}	
			if (!x) {
				x = rt;
				continue;
			}
			for (PNode y = x->s[k]; y; y = y->p) {
				if (y->a) {
					r[rl++] = y->a;
				}	
			}
			x = x->s[k];
		}
		if (rl) {
			sort(r, r + rl);
			total += rl = unique(r, r + rl) - r;
			printf("web %d:", a);
			for (int i = 0; i < rl; i++) {
				printf(" %d", r[i]);
			}
			puts("");
		}
		return total;
	}
};
//type definition
typedef long long LL;
//global variable
ACA aca;
int n, m;
char ask[maxn];
//access and mutator
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
	for (char c = 0; c < 127; c++) {
		printf("%d %c\n", c, c);
	}
	puts("");
#endif
	while (~scanf("%d", &n)) {
		aca.Init();
		for (int i = 0; i < n; i++) {
			char b[400];
			scanf("%s", b);
			aca.Insert(i + 1, b, strlen(b));
		}
		aca.Link();
		scanf("%d\n", &m);
		int total = 0;
		for (int i = 0; i < m; i++) {
			scanf("%[^\n]\n", ask);
			total += (bool)aca.Search(i + 1, ask, strlen(ask));
		}
		printf("total: %d\n", total);
	}
	return 0;
}
