#include<bits/stdc++.h>
using namespace std;
#define LL long long 

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i==1){
            puts("2");
            continue;
        }
        printf("%I64d\n",1ll * i * (i+1) * (i+1) - i + 1);
    }
    return 0;
}
    
