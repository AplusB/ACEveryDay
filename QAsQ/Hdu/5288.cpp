#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int maxn = 112345;
const int mod = 1e9+7;

vector<int> frc[maxn];

void init(){
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            frc[j].push_back(i);
        }
    }
}

LL l[maxn],r[maxn];
LL las[maxn];
int arr[maxn];


int main(){
    int n;
    init();
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<maxn;i++){
            l[i] = las[i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(auto x : frc[arr[i]]){
                l[i] = max(l[i],las[x]);
            }
            las[arr[i]] = i;
        }
        for(int i=0;i<maxn;i++){
            r[i] = las[i] = n+1;
        }
        for(int i=n;i>=1;i--){
            for(auto x : frc[arr[i]]){
                r[i] = min(r[i],las[x]);
            }
            las[arr[i]] = i;
        }
        LL ans = 0;
        for(int i=1;i<=n;i++){
            (ans += (i-l[i])*(r[i]-i))%=mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}









    
