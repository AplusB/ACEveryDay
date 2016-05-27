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
vector<long long> v;

long long gcd(long long a, long long b) {
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
    int t;
    scanf("%d", &t);
    FOR(_t, 1, t) {
        int n;
        v.clear();
        scanf("%d", &n);
        REP(i, n) {
            long long tmp;
            scanf("%lld", &tmp);
            v.push_back(tmp); 
        }

        vector<long long>::iterator it = v.begin();
        long long cur = *it;
        long long g = -1;
        it++;
        while (it != v.end()) {
            long long curr2 = *it;
            g = gcd(cur, curr2);
            cur *= curr2;
            cur /= g;
            it++;
        }
        printf("%lld\n", cur);

    }
    return 0;
}
