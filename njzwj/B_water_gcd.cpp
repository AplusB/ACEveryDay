#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
    return (y==0)?x:gcd(y, x%y);
}

int main() {
    ll x, y;
    while (scanf("%lld%lld", &x, &y)!=EOF) {
        printf("%10lld%10lld    ", x, y);
        if (gcd(x, y)==1) printf("Good Choice\n");
        else printf("Bad Choice\n");
        printf("\n");
    }
    return 0;
}
