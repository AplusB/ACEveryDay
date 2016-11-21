#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;

char mp[3][maxn];
bool vis[3][maxn];

queue<pair<int,int> > Q;

bool judge(int m){
    memset(vis,0,sizeof(vis));
    while(Q.empty()==false) Q.pop();
    int x = -1, y = 0;
    for(int i = 0 ; i < 3 ; i ++){
        if(mp[i][y] == 's'){
            x = i;
            break;
        }
    }
    Q.push(make_pair(x,y));
    vis[x][y] = true;
    while(Q.empty()==false){
        x = Q.front().first, y = Q.front().second;
        if(y >= m - 1) return true;
        Q.pop();
        if(mp[x][y+1]) continue;
        y++;
        if(y != 1){
            if(mp[x][y+1] || mp[x][y+2]) continue;
            y+=2;
        }
        for(int d = -1 ; d <= 1; d++){
            int nx = x + d;
            //printf("%d %d %d %d\n",0 <= nx , nx < 3 , vis[nx][y]==false , mp[nx][y]);
            if(0 <= nx && nx < 3 && vis[nx][y]==false && mp[nx][y] == false){
                vis[nx][y] = true;
                Q.push(make_pair(nx,y));
            }
        }
    }
    return false;
}

int main(){
    int T;
    scanf("%d",&T);
    int m,k;
    while(T-- && ~scanf("%d %d",&m,&k)){
        for(int i = 0 ; i < 3 ; i ++) scanf("%s",&mp[i]);
        for(int i = 0 ; i < 3 ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(mp[i][j] != 's') mp[i][j] = isalpha(mp[i][j]);
            }
        }
        puts(judge(m)?"YES":"NO");
    }
    return 0;
}
