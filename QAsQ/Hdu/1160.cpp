#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
#define LL long long

struct Mic{
    int w,s;
    int id;
    void init(int W,int S,int i){
        w = W,s = S,id = i;
    }
};

bool cmp(Mic a,Mic b){
    return a.w < b.w;
}
const int maxn = 1123;
Mic mic[maxn];
int dp[maxn],pre[maxn];

int main(){
    int len = 1;
    int w,s;
    while(~scanf("%d %d",&w,&s)){
        mic[len].init(w,s,len);
        len++;
    }
    len--;
    sort(mic+1,mic+len+1,cmp);
    memset(dp,0,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=len;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(mic[j].w < mic[i].w && mic[j].s > mic[i].s && dp[j]+1 > dp[i]){
                pre[i] = j;
                dp[i] = dp[j]+1;
            }
        }
    }
//    for(int i=1;i<=len;i++){
//        printf("%d %d\n",mic[i].w,mic[i].s);
//    }
    int ans = max_element(dp+1,dp+1+len)-dp;
    stack<int>anw;
    int lo = ans;
    while(lo!=-1){
        anw.push(mic[lo].id);
//        printf("%d () %d\n",mic[lo].w,mic[lo].s);
        lo = pre[lo];
    }
    printf("%d\n",dp[ans]);
    while(anw.empty()==false){
        printf("%d\n",anw.top());
        anw.pop();
    }
    return 0;
}
