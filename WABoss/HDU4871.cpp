#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF (1<<30)
#define MAXN 33333
#define MAXM 66666*2

struct Edge{
    int v,w,next;
}edge[MAXM];
int NE,head[MAXN];
void addEdge(int u,int v,int w){
    edge[NE].v=v; edge[NE].w=w;
    edge[NE].next=head[u]; head[u]=NE++;
}

int d[MAXN];
bool vis[MAXN];
void SPFA(int n){
    for(int i=1; i<=n; ++i){
        d[i]=INF; vis[i]=0;
    }
    d[1]=0; vis[1]=1;
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int u=que.front(); que.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next){
            int v=edge[i].v;
            if(d[v]>d[u]+edge[i].w){
                d[v]=d[u]+edge[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
        vis[u]=0;
    }
}

struct Node{
    int u,v,w;
    bool operator<(const Node &nd)const{
        if(u==nd.u) return nd.v<v;
        return u<nd.u;
    }
}node[MAXM];
int cnt;

void dfs(int u){
    vis[u]=1;
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(vis[v] || d[u]+edge[i].w!=d[v]) continue;
        node[cnt].u=u; node[cnt].v=v; node[cnt].w=edge[i].w;
        ++cnt;
        dfs(v);
    }
}

int size[MAXN];
void getsize(int u,int fa){
    size[u]=1;
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(vis[v] || v==fa) continue;
        getsize(v,u);
        size[u]+=size[v];
    }
}
int mini,cen;
void getcen(int u,int fa,int &tot){
    int res=tot-size[u];
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(vis[v] || v==fa) continue;
        res=max(res,size[v]);
        getcen(v,u,tot);
    }
    if(res<mini){
        mini=res;
        cen=u;
    }
}
int getcen(int u){
    getsize(u,u);
    mini=INF;
    getcen(u,u,size[u]);
    return cen;
}

int k;
int a_val[MAXN],a_cnt[MAXN],a_rec[MAXN],an,b_val[MAXN],b_cnt[MAXN],b_rec[MAXN],bn;
bool tag[MAXN];
int ans_val,ans_cnt;
void conqur_dfs(int u,int fa,int val,int tot){
    if(b_val[tot]<val){
        b_val[tot]=val;
        b_cnt[tot]=1;
        if(!tag[tot]){
            tag[tot]=1;
            b_rec[bn++]=tot;
        }
    }else if(b_val[tot]==val){
        ++b_cnt[tot];
    }
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(vis[v] || v==fa) continue;
        conqur_dfs(v,u,val+edge[i].w,tot+1);
    }
}
void conqur(int u){
    an=0;
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(vis[v]) continue;
        bn=0;
        conqur_dfs(v,v,edge[i].w,1);
        for(int j=0; j<bn; ++j){
            if(b_rec[j]==k-1){
                if(b_val[b_rec[j]]>ans_val){
                    ans_val=b_val[b_rec[j]];
                    ans_cnt=b_cnt[b_rec[j]];
                }else if(b_val[b_rec[j]]==ans_val){
                    ans_cnt+=b_cnt[b_rec[j]];
                }
            }else if(b_rec[j]<k-1){
                int tmp=k-1-b_rec[j];
                if(a_cnt[tmp]==0) continue;
                if(b_val[b_rec[j]]+a_val[tmp]>ans_val){
                    ans_val=b_val[b_rec[j]]+a_val[tmp];
                    ans_cnt=b_cnt[b_rec[j]]*a_cnt[tmp];
                }else if(b_val[b_rec[j]]+a_val[tmp]==ans_val){
                    ans_cnt+=b_cnt[b_rec[j]]*a_cnt[tmp];
                }
            }
        }
        for(int j=0; j<bn; ++j){
            int tmp=b_rec[j];
            tag[tmp]=0;
            a_rec[an++]=tmp;
            if(a_val[tmp]<b_val[tmp]){
                a_val[tmp]=b_val[tmp];
                a_cnt[tmp]=b_cnt[tmp];
            }else if(a_val[tmp]==b_val[tmp]){
                a_cnt[tmp]+=b_cnt[tmp];
            }
            b_val[tmp]=0;
            b_cnt[tmp]=0;
        }
    }
    for(int i=0; i<an; ++i){
        a_val[a_rec[i]]=0;
        a_cnt[a_rec[i]]=0;
    }
}

void divide(int u){
    u=getcen(u);
    vis[u]=1;
    conqur(u);
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(vis[v]) continue;
        divide(v);
    }
}

int main(){
    int t,n,m,a,b,c;
    scanf("%d",&t);
    while(t--){
        NE=0;
        memset(head,-1,sizeof(head));
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<m; ++i){
            scanf("%d%d%d",&a,&b,&c);
            node[i<<1].u=a; node[i<<1].v=b; node[i<<1].w=c;
            node[i<<1|1].u=b; node[i<<1|1].v=a; node[i<<1|1].w=c;
        }
        sort(node,node+(m<<1));
        for(int i=0; i<(m<<1); ++i){
            addEdge(node[i].u,node[i].v,node[i].w);
        }
        SPFA(n);
        cnt=0;
        memset(vis,0,sizeof(vis));
        dfs(1);
        NE=0;
        memset(head,-1,sizeof(head));
        for(int i=0; i<cnt; ++i){
            addEdge(node[i].u,node[i].v,node[i].w);
            addEdge(node[i].v,node[i].u,node[i].w);
        }
        memset(vis,0,sizeof(vis));
        ans_val=0; ans_cnt=0;
        divide(1);
        printf("%d %d\n",ans_val,ans_cnt);
    }
    return 0;
}
