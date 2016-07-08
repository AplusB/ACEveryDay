#include<bits/stdc++.h>
using namespace std;

const int maxn  = 212345;
vector<int> edge[maxn];

void Link(int st,int ed){
    edge[st].push_back(ed);
}

int dis[maxn];
queue<int> Q;
void bfs(int st){
    memset(dis,-1,sizeof(dis));
    while(Q.empty()==false) Q.pop();
    Q.push(st);
    dis[st] = 0;
    while(Q.empty()==false){
        st = Q.front();
        Q.pop();
        for(auto x : edge[st]){
            if(dis[x] == -1){
                dis[x] = dis[st] + 1;
                Q.push(x);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        Link(i,i+1);
        Link(i+1,i);
    }
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        Link(i,x);
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        printf(i<n?"%d ":"%d\n",dis[i]);
    }
    return 0;
}
