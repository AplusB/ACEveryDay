# HDU 4734 F(x)

一个简单的数位dp



这题的时间卡的有点紧，因为T比较大

刚开始每组输入都重新计算dp数组，然后喜闻乐见的T了好久

重新设计状态让计算出来的dp数组和A无关，这样就可以多次利用了

```cpp
 #include<bits/stdc++.h>
using namespace std;

#define LL long long

const int maxn = 20;
int tw[maxn],num[maxn];
int dp[maxn][200000];

int dfs(int pos,bool bnd,int lef){
    if(pos < 0) return lef >= 0;
    if(lef < 0) return 0;
    int &ndp = dp[pos][lef];
    if(!bnd && ndp != -1){
        return ndp;
    }
    int ret = 0;
    int bound = bnd ? num[pos] : 9;
    for(int i=0;i<=bound;i++){
        if(i * tw[pos] > lef)
            break;
        ret += dfs(pos-1,bnd && i==bound,lef - i*tw[pos]);
    }
    if(!bnd)
        ndp = ret;
    return ret;
}

int cw(int x){
    int ret = 0,len = 0;
    while(x){
        ret += tw[len]*(x%10);
        x /= 10;
        len++;
    }
    return ret;
}

int cal(int b,int a){
    int len = 0;
    a = cw(a);
    while(b){
        num[len++] = b % 10;
        b /= 10;
    }
    return dfs(len-1,true,a);
}

int main(){
    tw[0] = 1;
    for(int i=1;i<maxn;i++){
        tw[i] = tw[i-1]*2;
    }
    int icase = 1;
    int T;
    scanf("%d",&T);
    int b,a;
    memset(dp,-1,sizeof(dp));
    while(T-- && ~scanf("%d %d",&a,&b)){
        printf("Case #%d: %d\n",icase++,cal(b,a));
    }
    return 0;
}
```

