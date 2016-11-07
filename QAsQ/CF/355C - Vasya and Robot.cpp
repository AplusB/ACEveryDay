#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long  
LL INFF = 0x3f3f3f3f3f3f3f3fll;
int arr[maxn];

int main(){
    int n,l,r,ql,qr;
    scanf("%d %d %d %d %d",&n,&l,&r,&ql,&qr);
    LL sum = 0;
    for(int i = 1 ; i <= n;i++){
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    LL ans = INFF;
    sum *= r;
    ans = min(sum+(n-1)*qr,ans);
    int ruse = n , luse = 0;
    for(int i = 1 ; i <= n;i++){
        luse ++,ruse--;
        sum -= r * arr[i];
        sum += l * arr[i];
        int off = 0;
        if(abs(luse-ruse) > 1){
            off = (abs(luse-ruse)-1) * (luse > ruse ? ql : qr);
        }
        ans = min(ans,sum + off);
    }
    printf("%I64d\n",ans);
    return 0;
}
