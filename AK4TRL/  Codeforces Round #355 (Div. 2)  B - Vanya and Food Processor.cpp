#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
#ifdef _CONSOLE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, h, k;
    long long ans = 0;
    scanf("%d%d%d",&n,&h,&k);
    int x, temp = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d",&x);
        if(x + temp > h){
            ans++;
            temp = 0;
        }
        temp += x;
        ans = ans + temp / k;
        temp %= k;
    }
    if(temp)ans++;
    printf("%I64d\n",ans);
    
    return 0;
}
