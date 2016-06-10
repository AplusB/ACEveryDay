#include<bits/stdc++.h>
using namespace std;
#define LL long long

struct node{
    int ed;
    int t,d;
    node(){}
    node(int ed,int t,int d):ed(ed),t(t),d(d){}
};

const int maxn = 550;
int temp[maxn];

vector<node>edge[maxn];

void Link(int st,int ed,int t,int d){
    edge[st].push_back(node(ed,t,d));
}

queue<int> Q;
bool vis[maxn];

void spfa(int st,int *dis,function<int(node)> w,function<bool(int,node)> checker,int *pr = temp){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(int)*maxn);
    memset(pr,-1,   sizeof(int)*maxn);
    while(Q.empty()==false){
        Q.pop();
    }
    dis[st] = 0,vis[st] = true;
    Q.push(st);
    while(Q.empty()==false){
        st = Q.front(),Q.pop();
        vis[st] = false;
        for(auto & val : edge[st]){
            if( checker(st,val) ){
                int ed = val.ed,v = w(val);
                if(dis[ed] > dis[st] + v){
                    dis[ed] = dis[st] + v;
                    pr[ed] = st;
                    if(vis[ed]==false){
                        vis[ed] = true;
                        Q.push(ed);
                    }
                }
            }
        }
    }
}
int tpr[maxn],dpr[maxn];
int tdis[maxn],ddis[maxn];

vector<int> getans(int *s,int ed){
     vector<int> ans;
     while(ed != -1){
        ans.push_back(ed);
        ed = s[ed];
     }
     reverse(ans.begin(),ans.end());
     return ans;
}

void outans(vector<int> ans){
    for(int i=0;i<ans.size();i++){
        printf(i<ans.size()-1?"%d => ":"%d\n",ans[i]);
    }
}

int main(){
    int n,m;
    int st,ed,ow,d,t;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d %d %d",&st,&ed,&ow,&d,&t);
        Link(st,ed,t,d);
        if(!ow) Link(ed,st,t,d);
    }
    scanf("%d %d",&st,&ed);
    auto gett = [](node x){return x.t;};
    auto getd = [](node x){return x.d;};
    auto always = [](int st,node x){return true;};
    spfa(st,tdis,gett,always);
    spfa(st,ddis,getd,always);
    spfa(st
         ,temp
         ,getd
         ,[=](int st,node val){return tdis[st]+val.t == tdis[val.ed];}
         ,tpr);

    spfa(st
         ,temp
         ,[](node x){return 1;}
         ,[=](int st,node val){return ddis[st]+val.d == ddis[val.ed];}
         ,dpr);

    auto tans = getans(tpr,ed),dans = getans(dpr,ed);
    if(tans == dans){
        printf("Time = %d; Distance = %d: ",tdis[ed],ddis[ed]);
        outans(tans);
    }
    else{
        printf("Time = %d: ",tdis[ed]);
        outans(tans);
        printf("Distance = %d: ",ddis[ed]);
        outans(dans);
    }
    return 0;
}
