#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 20;
int n[maxn],m[maxn];
int an,bn;
int arr[maxn];
bool vis[maxn];

int inser(int x,int *s){
    if(x == 0){
        s[0] = 0;
        return 1;
    }
    int len = 0;
    while(x){
        s[len++] = x % 7;
        x /= 7;
    }
    reverse(s,s+len);
    return len;
}
void out(int *s,int n){
    for(int i=0;i<n;i++){
        printf(i<n-1?"%d ":"%d\n",s[i]);
    }
}

bool jud(int *s,int *p,int n){
    for(int i=0;i<n;i++){
        if(s[i] > p[i])
            return false;
        if(s[i] < p[i])
            return true;
    }
    return true;
}

int dfs(int use){
    if(use == an + bn){
        //if(jud(arr,n,an) && jud(arr+an,m,bn))
        //    out(arr,use);
        return jud(arr,n,an) && jud(arr+an,m,bn);
    }
    int ret = 0;
    for(int i=0;i<7;i++){
        if(vis[i]) continue;
        vis[i] = true;
        arr[use] = i;
        ret += dfs(use+1);
        vis[i] = false;
    }
    return ret;
}


int getans(int a,int b){
    an = inser(a-1,n);
    bn = inser(b-1,m);
    memset(vis,0,sizeof(vis));
    //out(n,an);
    //out(m,bn);
    return dfs(0);
}

int main(){
    int N,M;
    cin>>N>>M;
    cout<<getans(N,M);
    return 0;
}
