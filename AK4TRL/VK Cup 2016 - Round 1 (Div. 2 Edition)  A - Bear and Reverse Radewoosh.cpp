#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,c,p[10005],t[10005];
int main() {
#ifdef _CONSOLE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%lld%lld", &n,&c);
    for(int i = 0; i < n; ++i)
        scanf("%I64d",&p[i]);
        
    for(int i = 0; i < n; ++i)
        scanf("%I64d",&t[i]);
        
    LL ans1=0;
    LL pre=0;
    for(int i = 0; i < n; ++i){
        pre += t[i];
        ans1 += max(0LL,p[i] - pre * c);
    }
    LL ans2 = 0;
    pre = 0;
    for(int i = n - 1; i >= 0; --i){
        pre += t[i];
        ans2 += max(0LL,p[i] - pre * c);
    }
    if(ans1 > ans2)
        puts("Limak");
    else if(ans1 < ans2)
        puts("Radewoosh");
    else 
        puts("Tie");
    
    return 0;
}
