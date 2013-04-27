#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#define rep(i,l,r) for(int i = l; i <= r; ++i)
using namespace std;
typedef long long ll;
const int Mod = 1000000007;
int n,m,k,map[30][30];
bool used[30];

ll dfs(int x,int y)
{
	if(y > m) return dfs(x + 1,1);
	if(x > n) return 1;
	bool cant[11]; memset(cant,0,sizeof(cant));
	rep(i,1,x)
		rep(j,1,y)
		if(!(i == x && j == y) && map[i][j])
			cant[map[i][j]] = true;
	rep(i,x,n)
		rep(j,y,m)
		if(!(i == x && j == y) && map[i][j])
			cant[map[i][j]] = true;
	ll ret = 0;
	rep(col,1,k)
		if(used[col] && !cant[col]){
			if(map[x][y] && map[x][y] != col) continue;
			int his = map[x][y];
			map[x][y] = col;
			ret = (ret + dfs(x,y + 1)) % Mod;
			map[x][y] = his;
		}
	int newcol = 0,col = 0;
	rep(i,1,k)
		if(!used[i]){
			++newcol;
			col = i;
		}
	if(newcol && map[x][y] == 0){
		used[col] = true;
		map[x][y] = col;
		ret = (ret + newcol * dfs(x,y + 1) % Mod) % Mod;
		map[x][y] = 0;
		used[col] = false;
	}
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(n + m - 1 > k){
		puts("0"); return 0;
	}
	rep(i,1,n)
		rep(j,1,m){
			scanf("%d",&map[i][j]);
			if(map[i][j]) used[map[i][j]] = true;
		}
	cout<<dfs(1,1)<<endl;
	return 0;
}
