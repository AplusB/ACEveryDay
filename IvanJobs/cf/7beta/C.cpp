#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
#include <iostream>

using namespace std;


#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

template <class T>
T exgcd(T m, T n, T& x, T& y) {
  T x1, y1, x0, y0;
  x0 = 1; y0 = 0;
  x1 = 0; y1 = 1;
  x = 0; y = 1;
  T r = m % n;
  T q = (m - r) / n;
  while(r != 0) {
    x=x0-q*x1; y=y0-q*y1;
    x0=x1; y0=y1;
    x1=x; y1=y;
    m=n; n=r; r=m%n;
    q=(m-r)/n;
  }
  return n;
}

int main() {
    long long A, B, C;
    cin>>A>>B>>C;
    if (A == 0) {
      if (C % B != 0) cout<<-1<<endl;
      else cout<<"1 "<< -1 * C / B<<endl;
      return 0;
    }

    if (B == 0) {
      if (C % A != 0) cout<<-1<<endl;
      else cout<<-1 * C / A << " 1"<<endl;
      return 0;
    }
    long long g, x, y;
    g = exgcd(A, B, x, y);
    if (C % g != 0) cout<<-1<<endl;
    else {
      cout<<-1 * C / g * x<<" "<<-1 * C / g * y<<endl;
    }
    return 0;
}
