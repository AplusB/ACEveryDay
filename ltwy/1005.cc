#include <bits/stdc++.h>
using namespace std;
int T;
int n,k;
long long C[40][40];
long long D[40];
void init(){
    for(int i=0; i<=30; i++)
        C[i][i] = C[i][0] = 1;
    D[0] = 1;
    for(int i=1; i<=30; i++)
        D[i] = D[i-1] * i;
    for(int i=1; i<=30; i++)
        for(int j=1; j<=i; j++)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
}
int main() {
    cin>>T;
    init();
    for(int icase = 1; icase<=T; icase++) {
        scanf("%d %d", &n, &k);
        printf("Case %d: ", icase);
        printf("%lld\n", (long long)C[n][k] * (long long)C[n][k] * D[k]);
    }
    return 0;
}