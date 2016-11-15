#include<bits/stdc++.h>
using namespace std;

const int maxn = 512345;

int main(){
    int a2,a3,a5,a6;
    scanf("%d %d %d %d",&a2,&a3,&a5,&a6);
    int ans = min(a2,min(a5,a6));
    a2 -= ans;
    ans *= 256;
    ans += min(a2,a3) * 32;
    printf("%d\n",ans);
    return 0;
}
