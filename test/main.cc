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

namespace dwylkz {

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLl;
typedef vector<string> VS;
typedef map<int, int> MII;

template<class Y, class X>
Y Cast(const X& x)
{
  stringstream ss;
  ss << x;

  Y y;
  ss >> y;
  return y;
}

template<class T>
istream& operator >> (istream& is, vector<T>& vs)
{
  for (size_t i = 0; i < vs.size(); i++)
    is >> vs[i];
  return is;
}

template<class T>
ostream& operator << (ostream& os, const vector<T>& vs)
{
  for (size_t i = 0; i < vs.size()-1; i++)
    os << vs[i] << " ";
  os << vs.back() << endl;
  return os;
}

template<class T>
map<T, int> Discrete(const vector<T>& vs)
{
  map<T, int> m;
  for (auto& v: vs)
    m[v] = 1;

  int rank = 0;
  for (auto& mi: m)
    mi.second = rank++;
  return m;
}

template<class T, class F>
void Map(T xs, F f)
{
  for_each(xs.begin(), xs.end(), f);
}

template<class T, class R, class F>
R Fold(T xs, const R& init, F f)
{
  R ret = init;
  for (auto x: xs)
     ret = f(ret, x);
  return ret;
}

string Format(const string& fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);

  char* buff = new char[vsnprintf(NULL, 0, fmt.data(), ap)+2];
  vsprintf(buff, fmt.data(), ap);

  va_end(ap);

  string ret(buff);
  delete buff;

  return ret;
}

}
using namespace dwylkz;

int main()
{
  VS as(5);
  cin >> as;

  auto m = Discrete(as);
  Map(as, [&](string& s){cout << m[s] << " ";});

  string sum = Fold(as, string(""), plus<string>());
  cout << Format("(%s)", sum.data()) << endl;

  return 0;
}
