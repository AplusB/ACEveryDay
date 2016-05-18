#include <bits/stdc++.h>
using namespace std;
int T;
const int MOD = 1e7+7;
int a[100100];
int n;
int main() {
    cin>>T;
    for(int icase = 1; icase <= T; icase++) {
        scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
        cin>>n;
        for(int i=0; i<=5; i++)
            a[i] %= MOD;
        printf("Case %d: ", icase);
        if(n<6) {
            printf("%d\n", a[n]);
            continue;
        }
        for(int i=6; i<=n; i++) {
            a[i] = a[i-1] + a[i-2] + a[i-3] + a[i-4] + a[i-5] + a[i-6];
            a[i] %= MOD;
        }
        printf("%d\n", a[n]);
    }
    return 0;
}