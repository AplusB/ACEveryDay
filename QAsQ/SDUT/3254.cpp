#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn  = 450;

int arr[maxn][maxn];
int v[maxn];

int n;
int cal(int *l,int *r,int k){
    int st,ed;
    st = ed = 0;
    for(int i=0;i<=n;i++){
        v[i] = r[i] - l[i];
    }
    while(ed <= n && v[ed] < k){
        ed++;
    }
    if(ed > n)
        return n*n;
    int ret = ed;
    while(ed<=n){
        if(v[ed]-v[st] >= k){
            ret = min(ret,ed-st);
            st++;
        }
        else{
            ed++;
        }
    }
    return ret;
}


int main(){
    int T;
    scanf("%d",&T);
    int k;
    while(T-- && ~scanf("%d %d",&n,&k)){
        memset(arr,0,sizeof(arr));
        int x,y;
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            arr[x][y]++;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                arr[i][j] += arr[i][j-1];
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                arr[i][j] += arr[i-1][j];
            }
        }
        int ans = n*n;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans = min(ans,(j-i)*cal(arr[i],arr[j],k));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
