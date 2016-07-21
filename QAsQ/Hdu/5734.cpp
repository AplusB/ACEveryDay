#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 112345;
LL arr[maxn];

int main(){
    int T;
    scanf("%d",&T);
    LL n;
    while(T-- && ~scanf("%I64d",&n)){
        LL sum = 0;
        LL fz = 0;
        for(int i=0;i<n;i++){
            scanf("%I64d",&arr[i]);
            sum += arr[i] * arr[i];
            fz += abs(arr[i]);
        }
        fz = sum * n- fz * fz;
        LL fm = n;
        LL g = __gcd(fz,fm);
        fz /= g;
        fm /= g;
        printf("%I64d/%I64d\n",fz,fm);
    }
    return 0;
}
