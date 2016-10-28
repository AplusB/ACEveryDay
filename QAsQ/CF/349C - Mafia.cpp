#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long 
const LL INFF = 0x3f3f3f3f3f3fll;

LL arr[maxn];
int n;

bool check(LL x){
    LL ret = 0;
    for(int i = 0;i<n;i++){
        ret += x - arr[i];
    }
    return ret >= x;
}

LL cal(){
    LL st = *max_element(arr,arr+n),ed = INFF;
    LL ans = -1;
    while(st <= ed){
        LL mid = (st + ed)>>1;
        if(check(mid)){
            ans = mid;
            ed = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%I64d",&arr[i]);
    }
    printf("%I64d\n",cal());
    return 0;
}
