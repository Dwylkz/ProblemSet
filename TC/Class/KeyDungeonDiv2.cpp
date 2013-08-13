// BEGIN CUT HERE

// END CUT HERE
#line 5 "KeyDungeonDiv2.cpp"
#include <string>
#include <vector>
using namespace std;
class KeyDungeonDiv2 {
	public:
	int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {
    int rv = 0;
		for (int i = 0; i < doorR.size(); i++) {
      if (doorR[i] > keys[0]+keys[2] || doorG[i] > keys[1]+keys[2])
        continue;
      int r = doorR[i] > keys[0]? doorR[i]-keys[0]: 0;
      rv += (doorR[i] <= keys[0]+r && doorG[i] <= keys[1]+keys[2]-r);
    }
    return rv;
	}
};
