#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int maxn = 112345;
char arr[maxn];
bool vis[maxn];
int bef[60];

int getid(char c){
    if(isupper(c))
        return c - 'A';
    else
        return c - 'a' + 26;
}

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",arr+1);
    for(int i=1;i<=n;i++){
        vis[getid(arr[i])] = true;
    }
    int all = 0;
    for(int i=0;i<60;i++){
        if(vis[i]) all++;
    }
    memset(bef,-1,sizeof(bef));
    int ans = n;
    for(int i=1;i<=n;i++){
        bef[getid(arr[i])] = i;
        int low = n;
        for(int j=0;j<60;j++){
            if(vis[j]){
                low = min(low,bef[j]);
            }
        }
        if(low == -1) continue;
        ans = min(ans,i-low+1);
    }
    printf("%d\n",ans);
    return 0;
}
