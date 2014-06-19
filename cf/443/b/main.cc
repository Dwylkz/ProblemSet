#include <iostream>
#include <string>
using namespace std;

string s;
int k;

bool Equal(int i, int l)
{
	int n = s.size();
	string t = s;
	for (int j = 0; j < k; j++)
		t += 'h';
	for (int j = i; j < i+l; j++) {
		if (j+l >= n+k)
			return 0;
		
		if (j+l >= n)
			t[j+l] = t[j];
		
		if (t[j] != t[j+l])
			return 0;
	}
	return 1;
}

bool Look(int l)
{
	for (int i = 0; i < s.size(); i++)
		if (Equal(i, l))
			return 1;
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	while (cin >> s >> k)
		for (int i = s.size()+k; i >= 0; i--)
			if (Look(i)) {
				cout << i*2 << endl;
				break;
			}
	return 0;
}
