#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;
char arr[maxn];

int main(){
    scanf("%s",arr);
    int ans = 0,should = 0,tim = -1;
    for(int i = 0 ; arr[i] ;i++){
        if(arr[i] == 'F'){
            int v = i - should;
            if(v) v = max(v,tim + 1);
            ans = max(ans,v);
            should ++;
            tim = v; 
        }
    }
    printf("%d\n",ans);
    return 0;
}
