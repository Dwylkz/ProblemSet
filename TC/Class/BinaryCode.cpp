#include <string>
#include <iostream>
#include <vector>
using namespace std;
class BinaryCode {
public: 
	typedef vector<string> VS;
	VS decode(string q) {
		VS ps;
		int l = q.length();
		for (int i = 0; i < l; i++) {
			q[i] -= '0';
		}
		ps.push_back(decodeblock(0, q, l));
		ps.push_back(decodeblock(1, q, l));
		#if 0
			for (int i = 0; i < l; i++) {
				q[i] += '0';
			}
			cout << q << endl;
			cout << ps[0] << endl;
		#endif
		return ps;
	}
	string decodeblock(int p0, string &q, int l) {
		int tp[55];
		tp[0] = p0;
		tp[1] = q[0] - p0;
		for (int i = 2; i < l; i++) {
			tp[i] = q[i - 1] - tp[i - 1] - tp[i - 2];
		}
		string p = q;
		for (int i = 0; i < l; i++) {
			if (1 < tp[i] || 2 < q[0] || q[l - 1] != tp[l - 1] + tp[l - 2]) {
				p = "NONE";
				break;
			}
			p[i] = tp[i] + '0';
		}
		return p;
	}
};
