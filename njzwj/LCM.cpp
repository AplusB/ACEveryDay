#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
    return (b==0)?a:gcd(b, a%b);
}

int main() {
    LL ans;
    int n, tmp, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%lld", &ans);
        for (int i=1;i<n;++i) {
            scanf("%d", &tmp);
            ans=ans/gcd(ans, tmp)*tmp;
        }
        printf("%lld\n", ans);
    }
}
