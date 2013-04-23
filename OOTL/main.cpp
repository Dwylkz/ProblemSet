#include <vector>
using namespace std;
struct Graph{
	struct Edge{
		int v, t; 
		Edge(int _v = 0, int _t = 0){
			v = _v, t = _t;
		}
	};
	typedef vector<Edge> VE;
	typedef vector<int> VI;
	VE E;
	VI L;
	Graph(int V){
		L.clear();
		E.clear();
		for (int i = 0; i < V; i++) L.push_back(-1);
	}
	//AddEdge
	void AE(int u, int v){
		Edge t(v, L[u]);
		L[u] = E.size();
		E.push_back(t);
	}
};
struct Network: virtual Graph{
	struct Edge: Graph::Edge{
		int v, c, t;
		Edge(int _v = 0, int _c = 0, int _t = 0){
			v = _v, c = _c, t = _t;
		}
	};
	//AddEdge
	void AE(int u, int v, int c){
		Edge t(v, c, L[u]);
		L[u] = E.size();
		E.push_back(t);
	}
	//AddFlowEdge
	void AFE(int u, int v, int c){
		AE(u, v, c);
		AE(v, u, c);
	}
};
int main(){
	Network G(6);
	printf("%d\n", G.E.c);
	return 0;
}
