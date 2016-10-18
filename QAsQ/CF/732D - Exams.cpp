#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
int arr[maxn], d[maxn];
bool vis[maxn];

bool check(int ed,int m){
    memset(vis,0,sizeof(vis));
    vis[0] = true;
    int ned = 0;
    for(int i = ed;i>=1;i--){
        if(!vis[d[i]]){
            vis[d[i]] = true;
            ned += arr[d[i]];
            m--;
        }
        else{
            if(ned) ned--;
        }
    }
    return ned == 0 && m == 0;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&arr[i]);
    }
    arr[0] = -1;
    if(!check(n,m)){
        puts("-1");
    }
    else{
        int ans = n;
        int st = 1,ed = n;
        while(st <= ed){
            int mid = (st + ed) >> 1;
            if(check(mid,m)){
                ans = mid;
                ed = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
