#include<bits/stdc++.h>
using namespace std;

const int N = 1234;
#define LL long long 
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

int a[10],M;

LL f(int x){
    LL ret = 0;
    for(int i = M ; i >= 0 ; i --){
        ret = ret * x + a[i];
    }
    return ret;
}

LL m[N][N]; 
int s[N][N];
LL sum[N];
int n;

LL solve() {
    for(int i=1; i<=n; i++) {
        m[i][i] = 0;  
        s[i][i] = i;
    }
    for(int l=1; l<n; l++) {
        for(int i=1; i+l<=n; i++) {
            int j = i+l;
            LL tmp = INFF;
            int k = 0;
            for(int div=s[i][j-1]; div<=s[i+1][j];div++) {
                if(tmp > m[i][div] + m[div+1][j] + f(sum[j] - sum[i-1])) {
                    tmp = m[i][div] + m[div+1][j] + f(sum[j] - sum[i-1]);
                    k = div;
                }
            }
            m[i][j] = tmp;
            s[i][j] = k;
        }
    }
    return m[1][n];
}

int main(){
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        sum[0] = 0;
        for(int i=1; i<=n; i++) {
            int a;
            scanf("%d",&a);
            sum[i] = sum[i-1] + a;
        }
        scanf("%d",&M);
        for(int i = 0 ; i <= M ; i ++){
            scanf("%d",&a[i]);
        }
        printf("%lld\n",solve());
    }
    return 0;
}
