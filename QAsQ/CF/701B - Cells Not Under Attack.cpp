#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int maxn = 112345;
bool ix[maxn],iy[maxn];

vector<LL> anw;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x,y;
    memset(ix,0,sizeof(ix));
    memset(iy,0,sizeof(iy));
    LL ans = 1ll * n * n ;
    int xl = n,yl = n;
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        if(ix[x] == false){
            ans -= yl;
            ix[x] = true;
            xl--;
        }
        if(iy[y] == false){
            ans -= xl;
            iy[y] = true;
            yl--;
        }
        anw.push_back(ans);
    }
    for(int i=0;i<m;i++){
        printf(i<m-1?"%I64d ":"%I64d\n",anw[i]);
    }
    return 0;
}
