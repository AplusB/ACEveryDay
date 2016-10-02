#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long 
char arr[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%s",arr)){
        LL len = strlen(arr); 
        LL ans = 0,st = 0;
        for(int i=0;arr[i];i++){
            if(arr[i] == 'q'){
                st++;
            }
            else{
                if(st)
                    ans += st * (st+1) / 2;
                st = 0;
            }
        }
        if(st) ans += st * (st+1) / 2;
        printf("%I64d\n",ans);
    }
    return 0;
}
