#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 112345;
double loca[maxn];
double eps = 1e-6;

int main(){
    int T,icase = 1;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        loca[0] = 0;
        for(int i = 1;i <= n;i++){
            scanf("%lf",&loca[i]);
        }
        LL ans = 1;
        double bnd = loca[n] - loca[n-1];
        for(int i = n-1;i >= 1;i--){
            double seg = loca[i] - loca[i-1];
            LL tim = ceil(seg / bnd - eps);
            double rbnd = seg / tim;
            bnd = min(bnd,rbnd);
            ans += tim;
        }
        printf("Case #%d: %I64d\n",icase++,ans); 
    }
    return 0;
}
