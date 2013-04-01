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
	  maxn = 1e6 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//AC Automaton
//include: queue, cstring
//usage: obj.Init->obj.Link->(obj.$(others))*
struct ACA {
	const static int n = maxn,  //Total of nodes
		  m = 26,               //Size of charator set
		  shift = 'a';          //Charactor shift
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
	void Insert(char *s, int sl) {
		PNode x = rt;
		for (int i = 0; i < sl; i++) {
			int k = s[i] - shift;
			if (!x->s[k]) {
				x->s[k] = New();
			}
			x = x->s[k];
		}
		x->a++;
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
	int Search(char *s, int sl) {
		int total = 0;
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
				total += y->a;
				y->a = 0;
			}
			x = x->s[k];
		}
		return total;
	}
};
//type definition
typedef long long LL;
//global variable
ACA aca;
int n;
char ask[maxn];
//access and mutator
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		aca.Init();
		for (int i = 0; i < n; i++) {
			char b[100];
			scanf("%s", b);
			aca.Insert(b, strlen(b));
		}
		aca.Link();
		scanf("%s", ask);
		printf("%d\n", aca.Search(ask, strlen(ask)));
	}
	return 0;
}
