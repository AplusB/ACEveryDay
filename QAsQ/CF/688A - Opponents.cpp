#include<bits/stdc++.h>
using namespace std;

const int maxn = 150;
char arr[maxn];

bool jud(int n){
    scanf("%s",arr);
    for(int i=0;i<n;i++){
        if(arr[i]=='0')
            return false;
    }
    return true;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int ans = 0;
    int log = 0;
    while(k--){
        if(jud(n)){
            log = 0;
        }
        else{
            log ++;
            ans = max(ans,log);
        }
    }
    printf("%d\n",ans);
    return 0;
}
