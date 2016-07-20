#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;

int arr[maxn];

int getrot(int n){
    for(int i=1;i<=n;i++){
        if(arr[i] == i)
            return i;
    }
    return -1;
}

int vis[maxn];


int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int rot = getrot(n);
    memset(vis,0,sizeof(vis));
    int cnt = 1,ans = 0;
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            vis[i] = cnt;
            int x = i;
            while(vis[arr[x]] == 0){
                x = arr[x];
                vis[x] = cnt;
            }
            if(vis[arr[x]] == cnt){
                if(arr[x] != rot) ans++;
                if(rot == -1) rot = x;
                arr[x] = rot;
            }
            cnt++;
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        printf(i<n?"%d ":"%d\n",arr[i]);
    }
    return 0;
}
                
                


