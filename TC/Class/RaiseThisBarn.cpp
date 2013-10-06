#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <map>
#include <string>
#include <vector>
using namespace std;

class RaiseThisBarn {
  public:
    int calc(string str) {
      int result = 0;
      for (int i = 1; i < str.length(); i++) {
        int lc = 0, rc = 0;
        for (int j = 0; j < i; j++) lc += (str[j] == 'c');
        for (int j = i; j < str.length(); j++) rc += (str[j] == 'c');
        result += (lc == rc);
      }
      return result;
    }
};
