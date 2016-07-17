#include<cstdio>
#include<set>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define LL long long

const int maxn = 1123;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

char Map[maxn][maxn];
bool vis[maxn][maxn];

struct node{
    int x,y;
    node(int x,int y):x(x),y(y){}
};

bool & use(node v){
    return vis[v.x][v.y];
}
vector<node> arr;
queue<node> Q,temp;
int n,m;

auto in = [=](int x,int y){return 1<=x && x<=n && 1<=y && y<=m;};
auto iner = [=](node v){return in(v.x,v.y);};

void dfs(int x,int y){
    vis[x][y] = true;
    if(Map[x][y]=='1'){
        return;
    }
    for(int d=0;d<4;d++){
        int _x = dx[d] + x;
        int _y = dy[d] + y;
        if(vis[_x][_y]==false && in(x,y)){
            dfs(_x,_y);
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%d %d",&n,&m)){
        for(int i=1;i<=n;i++){
            scanf("%s",Map[i]+1);
        }
        memset(vis,0,sizeof(vis));
        dfs(1,1);
        arr.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    arr.push_back(node(i,j));
                }
            }
        }
        if(arr.size()==0){
            puts("0");
            continue;
        }
        auto sumer = [](node a){return a.x+a.y;};
        sort(arr.begin(),arr.end()
            ,[=](node a,node b){
            return sumer(a) > sumer(b);}
            );
        int hug = sumer(*arr.begin());
        while(Q.empty()==false) Q.pop();
        while(temp.empty()==false) temp.pop();
        auto down = [](node v){return node(v.x+1,v.y);};
        auto left = [](node v){return node(v.x,v.y+1);};
        auto mval = [=](node v){return Map[v.x][v.y]-'0';};
        int val = 2;
        printf("%d",mval(*arr.begin()));
        for(auto v : arr){
            if(sumer(v) != hug){
               break;
            }
            if(iner(down(v)) && !use(down(v))) use(down(v)) = true, val = min(val,mval(down(v))),Q.push(down(v));
            if(iner(left(v)) && !use(left(v))) use(left(v)) = true, val = min(val,mval(left(v))),Q.push(left(v));
        }
        for(int i=hug+1;i<=n+m;i++){
            printf("%d",val);
            int tv = 2;
            while(sumer(Q.front())==i){
                if(mval(Q.front())!= val){
                    Q.pop();
                    continue;
                }
                node D = down(Q.front());
                node L = left(Q.front());
                Q.pop();
                if(iner(D) && !use(D)) use(D)=true,Q.push(D),tv = min(tv,mval(D));
                if(iner(L) && !use(L)) use(L)=true,Q.push(L),tv = min(tv,mval(L));
            }
            val = tv;
        }
        puts("");
    }
    return 0;
}
