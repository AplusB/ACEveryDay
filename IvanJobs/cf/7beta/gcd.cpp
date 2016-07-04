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

using namespace std;


#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

template <class T>
T gcd(T a, T b) {
  while(b != 0) {
    T tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
