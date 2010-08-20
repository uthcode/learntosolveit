#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
typedef vector<int> VI;  typedef vector<vector<int> > VVI;
typedef vector<string> VS;  typedef vector<vector<string> > VVS;
typedef signed long long i64;  typedef unsigned long long u64;

int taken[128];

// NOTE: returns -1 for unmatched items.  nm is number of matchable items.
int bipartitematch(const vector<vector<int> > &m, int nm = 128) {
  vector<int> mat(nm, -1), ret(m.size(), -1);
  int i, j, x, y;
  int retn = 0;

  for( i = 0; i < m.size(); i++ ) {
    queue<int> q;
    vector<int> pred(m.size(), -1);
    q.push(i);
    pred[i] = -2;
    while( !q.empty() ) {
      x = q.front(); q.pop();
      for( j = 0; j < m[x].size(); j++ ) if( taken[m[x][j]] ) {
	cout<<m[x][j]<<endl;
        y = mat[m[x][j]];
        if( y == -1 ) goto found;
        if( pred[y] != -1 ) continue;
        pred[y] = x;
        q.push(y);
      }
    }
    continue;
found:  y = m[x][j];
    retn++;
    while( x != -2 ) {
      mat[y] = x;
      swap(ret[x], y);
      x = pred[x];
    }
  }
  return retn;
}

class Graduation {
public:
string moreClasses(string a, vector <string> b) {
  int i, j, k, x, y, z, n;
  string ret = "";
  VVI m;

  for( i = 0; i < b.size(); i++ ) {
    n = atoi(b[i].c_str());
    for( j = 0; j < n; j++ ) {
      m.push_back(VI());
      for( k = 0; k < b[i].size(); k++ ) if( !isdigit(b[i][k]) )
        m.back().push_back(b[i][k]);
    }
  }
  if( m.size() > 128 ) return "0";
  for( i = 0; i < a.size(); i++ ) taken[a[i]] = 1;
  n = m.size()-bipartitematch(m);
  x = 33;
  while( n ) {
    if( x >= 128 ) return "0";
    if( taken[x] ) {x++; continue;}
    taken[x] = 1;
    if (x >= 67)
	    cout<<x;
    z = m.size()-bipartitematch(m);
    if( z == n )
      taken[x] = 0;
    else
      ret += x;
    n = z;
    x++;
  }
  return ret;
}
}; 
int main(int argc, char *argv[])
{
	string a="A";
	vector <string> b;
	Graduation obj;
	b.push_back("2ABC");
	b.push_back("2DEF");
	cout<< obj.moreClasses(a,b);
}
