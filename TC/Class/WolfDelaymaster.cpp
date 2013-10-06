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

class WolfDelaymaster {
  public:
    string check(string str) {
      string no = "INVALID";
      for (int i = 0; i < str.length(); i++) {
        if (str[i] != 'w') return no; 
        int countw = 0, count;
        for ( ; i < str.length() && str[i] == 'w'; i++) countw++;
        if (i == str.length() || str[i] != 'o') return no;
        for (count = 0; i < str.length() && str[i] == 'o'; i++) count++;
        if (count != countw) return no;
        if (i == str.length() || str[i] != 'l') return no;
        for (count = 0; i < str.length() && str[i] == 'l'; i++) count++;
        if (count != countw) return no;
        if (i == str.length() || str[i] != 'f') return no;
        for (count = 0; i < str.length() && str[i] == 'f'; i++) count++;
        if (count != countw) return no;
        i--;
      }
      return "VALID";
    }
};
