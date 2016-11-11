#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(~scanf("%d",&n)){
        int ans = 0;
        long long x;
        while(n--){
            scanf("%I64d",&x);
            bool flag = false;
            while(x){
                ans += x % 256 == 97;
                x /= 256;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
