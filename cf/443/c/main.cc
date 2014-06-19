#include <iostream>
#include <string>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int N = 1e2+10;
const int M = 10;
typedef unordered_set<int> SI;
typedef unordered_map<int, SI> MISi;

const char col[] = "RGBYW";
int n;
int cs[N];

int Look(int s)
{
	SI all;
	for (int i = 0; i < n; i++)
		all.insert(cs[i]);
	
	int t[N] = {0};
	for (int i = 0; i < M; i++) {
		if (!(s>>i&1))
			continue;
		
		for (int j = 0; j < n; j++)
			if (cs[j]>>i&1)
				t[j] += 1<<i;
	}
	
	SI cur;
	for (int i = 0; i < n; i++)
		cur.insert(t[i]);
		
	return all.size()==cur.size();
}

int CB(int x)
{
	int ret = 0;
	while (x) {
		ret += x&1;
		x >>= 1;
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			string c;
			cin >> c;
			cs[i] = (1<<(strchr(col, c[0])-col))|(1<<(c[1]-'1'+5));
		}
		
		int ret = M;
		for (int i = (1<<M)-1; ~i; i--)
			if (Look(i))
				ret = min(ret, CB(i));
		
		cout << ret << endl;
	}
	return 0;
}
