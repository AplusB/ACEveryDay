#include<bits/stdc++.h>
using namespace std;

map<int,vector<pair<int,int> > >add,sub;
#define LL long long 

const int maxn = 112345;
const LL INFF = 0x3f3f3f3f3f3f3f3fll;
LL ans[maxn];

int main(){
    memset(ans,0x3f,sizeof(ans));
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int x,y;
    for(int i=0;i<k;i++){
        scanf("%d %d",&x,&y);
        add[x+y].push_back(make_pair(x,i));
        sub[x-y].push_back(make_pair(x,i));
    }
    LL st = 0;
    int dx = 1,dy = 1;
    x = y = 0;
    do{
        if(dx != dy){
            for(auto it : add[x + y]){
                int rx = it.first, id = it.second;
                ans[id] = min(ans[id],st + abs(rx - x));
            }
            add.erase(x+y);
        }
        else{
            for(auto it : sub[x - y]){
                int rx = it.first, id = it.second;
                ans[id] = min(ans[id],st + abs(rx - x));
            }
            sub.erase(x - y);
        } 
        int vx = dx == 1 ? n - x : x;
        int vy = dy == 1 ? m - y : y;
        int v = min(vx,vy);
        x += dx * v, y += dy * v;
        st += v;
        if(x == 0 || x == n) dx = -dx;
        else dy = -dy;
    }while((x != 0 && x != n) || (y != 0 && y != m));
    for(int i=0;i<k;i++){
        printf("%I64d\n",(ans[i] == INFF ? -1 : ans[i]));
    }
    return 0;
}

