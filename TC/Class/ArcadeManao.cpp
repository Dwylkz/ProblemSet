// BEGIN CUT HERE

// END CUT HERE
#line 5 "ArcadeManao.cpp"
#include <string>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 55;
class ArcadeManao {
	//structures
	//Linking list Graph
	//include: vector
	struct LLG {
		struct Edge {
			//Externs should be defined here
			int w;
			//Basic
			int v,       //Adjust node v
				next;    //Index of the next node v
		};
		const static int n = maxn * maxn;
		vector<Edge> E;    //Aarry in which Edges store
		int  L[n],         //Head of linking list of nodes
			 V;            //Total of nodes
		//Init
		//usage: obj.Init(int TotalOfNode)
		void Init(int _V = 0) {
			V = _V;
			E.clear();
			memset(L, -1, sizeof(L));
		}
		//AddEdge 
		//usage: obj.AddEdge(From, To, Extern)
		void AddEdge(int u, int v, int w) {
			Edge t =  {w, v, L[u]}; //rule: Node t = {Extern, Basic}
			L[u] = E.size();
			E.push_back(t);
		}
		//FlowAddEdge 
		//usage: obj.FlowAddEdge(From, To, Extern)
		void FlowAddEdge(int u, int v, int w, int x = 0) {
			AddEdge(u, v, w);
			AddEdge(v, u, x);
		}
	};
	int id;
	bool Check(int L, vector<vector<int> > &m, int u) {
		map<pair<int, int>, bool> h;
		LLG llg;
		llg.Init(id);
		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < m[i].size(); j++) {
				if (m[i][j]) {
					int k = m[i][j];
					for ( ; j < m[i].size() && m[i][j] == k; j++) {
						for (int l = 0; l <= L; l++) {
							if (0 <= i - l && m[i - l][j]) {
								pair<int, int> tp = make_pair(k, m[i - l][j]);
								if (h.find(tp) == h.end()) {
									h[tp] = 1;
									llg.AddEdge(k, m[i - l][j], 1);
								}
							}
							if (i + l < m.size() && m[i + l][j]) {
								pair<int, int> tp = make_pair(k, m[i + l][j]);
								if (h.find(tp) == h.end()) {
									h[tp] = 1;
									llg.AddEdge(k, m[i + l][j], 1);
								}
							}
						}
					}
				}
			}
		}
#if 0
		printf("L = %d hsize = %d u = %d\n", L, h.size(), u);
		for (map<pair<int, int>, bool>::iterator i = h.begin(); i != h.end(); i++) {
			printf("%d, %d\n", i->first.first, i->first.second);
		}
#endif
		queue<int> Q;
		bool vis[maxn * maxn];
		memset(vis, 0, sizeof(vis));
		Q.push(u);
		vis[u] = 1;
		while (!Q.empty()) {
			u = Q.front();
			Q.pop();
#if 0
			printf("u = %d\n", u);
#endif
			if (u == id - 1) {
				return 1;
			}
			for (int i = llg.L[u]; i != -1; i = llg.E[i].next) {
				int v = llg.E[i].v;
				if (!vis[v]) {
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
		return 0;
	}
	public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		int res = -1, l = 0, r = 100;
		id = 1;
		vector<vector<int> > map(level.size());
		for (int i = 0; i < level.size(); i++) {
			map[i].resize(level[i].length());
			for (int j = 0; j < level[i].length(); j++) {
				if (level[i][j] == 'X') {
					for ( ; j < level[i].length() && level[i][j] == 'X'; j++) {
						map[i][j] = id;
					}
					id++;
				} else {
					map[i][j] = 0;
				}
			}
		}
#if 0
		puts("map:");
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++) {
				printf("%5d", map[i][j]);
			}
			puts("");
		}
#endif
		while (l <= r) {
			int m = l + r >> 1;
			if (Check(m, map, map[coinRow - 1][coinColumn - 1])) {
				res = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return res;
	}
};
