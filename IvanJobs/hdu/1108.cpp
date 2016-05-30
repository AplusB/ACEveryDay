#include <stdio.h>
#include <vector>

#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

using namespace std;
template <typename T>

T gcd(T a, T b) {
    if (a == 0) return b;
    while (b != 0) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}
int main() {
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        int g = gcd(a, b);
        printf("%d\n", a * b / g);
    }
    return 0;
}
