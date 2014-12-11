#include <fstream>
#include <iostream>
#include <vector>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <cstdarg>
using namespace std;

int main()
{
  ifstream is;
  is.open("in");
  if (!is.is_open()) {
    cerr << "fuck " << endl;
    return -1;
  }

  int n;
  while (true) {
    is >> n;
    is.good();
    if (!is.good())
      break;
    cout << bool(is) << " " << is.good() << " " << n << endl;
  }
  is.close();
  return 0;
}
