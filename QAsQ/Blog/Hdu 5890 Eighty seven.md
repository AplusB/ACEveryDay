# Hdu 5890 Eighty seven 

有50个数，每次拿走至多三个数询问是否存在十个数满足和等于87。

---

可以用bitset压位跑一个背包

抠一抠常数就能过去惹

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 55;
int var[maxn];
int n;
int ans[maxn][maxn][maxn];

bitset<88>dp[10];

bool cal(){
    int a,b,c;
    int x,y,z;
    scanf("%d %d %d",&a,&b,&c);
    x = max(max(a,b),c);
    z = min(min(a,b),c);
    y = a + b + c - x - z;
    int &anw = ans[x][y][z];
    if(~anw) return anw;
    for(int i=0;i<=10;i++) dp[i].reset();
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        if(i == x || i == y || i == z || var[i] > 87) continue;
        for(int j=10;j>=1;j--){
            dp[j] |= dp[j-1]<<var[i];
        }
    }
    return anw = dp[10][87];
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- && ~scanf("%d",&n)){
        memset(ans,-1,sizeof(ans));
        for(int i=1;i<=n;i++){
            scanf("%d",&var[i]);
        }
        int q;
        scanf("%d",&q);
        while(q--){
            puts(cal()?"Yes":"No");
        }
    }
    return 0;
}
```

