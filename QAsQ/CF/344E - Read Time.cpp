#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 112345;
const LL INFF = 0x3f3f3f3f3f3f3f3fll;
LL h[maxn],p[maxn];
int n,m;

bool check(LL x){
    int pos = 0;
    for(int i=0;i<n;i++){
        LL far = h[i];
        if(p[pos] >= h[i]) far += x;
        else{
            if(p[pos] < h[i] - x) continue; 
            far = max(far,h[i] + (x - (h[i] - p[pos])) / 2);
            far = max(far,h[i] + (x - 2 * (h[i] - p[pos])));
        }
        while(pos < m && p[pos] <= far)
            pos++;
        if(pos == m) return true;
    }
    return pos == m;
}

LL solve(){
    LL st = 0,ed = INFF;
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
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%I64d",&h[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%I64d",&p[i]);
    }
    printf("%I64d\n",solve());
    return 0;
}
