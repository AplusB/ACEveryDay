#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;

struct node
{
  int to,t,w;
};
vector<node>g[1024];
int n,ans1,ans2;
vector<int>v1,v2;

void spfa1(int st,int ed)
{
  int inq[1024],dis[1024],pre[1024],cnt[1024];
  int u,v;
  for(int i=0;i<n;i++)
  {
    dis[i]=inf;
    pre[i]=-1;
    inq[i]=0;
    cnt[i]=0;
  }
  dis[st]=0;
  queue<int>q;
  q.push(st);
  while(!q.empty())
  {
    u=q.front();
    //printf("%d\n",u);
    inq[u]=0;
    q.pop();
    for(int i=0;i<g[u].size();i++)
    {
      v=g[u][i].to;
      if(dis[v]>dis[u]+g[u][i].t)
      {
        dis[v]=dis[u]+g[u][i].t;
        cnt[v]=cnt[u]+g[u][i].w;
        pre[v]=u;
        if(inq[v]==0)
        {
          q.push(v);
          inq[v]=1;
        }
      }
      else if(dis[v]==dis[u]+g[u][i].t)
      {
        if(cnt[v]>cnt[u]+g[u][i].w)
        {
          cnt[v]=cnt[u]+g[u][i].w;
          pre[v]=u;
          if(inq[v]==0)
          {
            q.push(v);
            inq[v]=1;
          }
        }
      }
    }
  }
  //printf("%d\n",ed);
  ans1=dis[ed];
  v1.clear();
  int k=ed;
  while(k!=-1)
  {
    v1.push_back(k);
    k=pre[k];
  }
}

void spfa2(int st,int ed)
{
  int inq[1024],dis[1024],pre[1024],cnt[1024];
  int u,v;
  for(int i=0;i<n;i++)
  {
    dis[i]=inf;
    pre[i]=-1;
    inq[i]=0;
    cnt[i]=0;
  }
  dis[st]=0;
  queue<int>q;
  q.push(st);
  while(!q.empty())
  {
    u=q.front();
    inq[u]=0;
    q.pop();
    for(int i=0;i<g[u].size();i++)
    {
      v=g[u][i].to;
      if(dis[v]>dis[u]+g[u][i].w)
      {
        dis[v]=dis[u]+g[u][i].w;
        cnt[v]=cnt[u]+1;
        pre[v]=u;
        if(inq[v]==0)
        {
          q.push(v);
          inq[v]=1;
        }
      }
      else if(dis[v]==dis[u]+g[u][i].w)
      {
        if(cnt[v]>cnt[u]+1)
        {
          cnt[v]=cnt[u]+1;
          pre[v]=u;
          if(inq[v]==0)
          {
            q.push(v);
            inq[v]=1;
          }
        }
      }
    }
  }
  ans2=dis[ed];
  v2.clear();
  int k=ed;
  while(k!=-1)
  {
    v2.push_back(k);
    k=pre[k];
  }
}

int main()
{
  int m,v11,v22,u,len,time;
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++)
  {
    g[i].clear();
  }
  for(int i=0;i<m;i++)
  {
    scanf("%d%d%d%d%d",&v11,&v22,&u,&len,&time);
    node tmp;
    tmp.to=v22;
    tmp.w=len;
    tmp.t=time;
    g[v11].push_back(tmp);
    if(u==0)
    {
      tmp.to=v11;
      g[v22].push_back(tmp);
    }
  }
  int st,ed;
  scanf("%d%d",&st,&ed);
  spfa1(st,ed);
  spfa2(st,ed);
  
  int f=0;
  if(v1.size()==v2.size())
  {
    for(int i=0;i<v1.size();i++)
    {
      if(v1[i]!=v2[i]) 
      {
        f=1;break;
      }
    }
  }
  else f=1;
  
  if(f==0)
  {
    printf("Time = %d; ",ans1);
    printf("Distance = %d: ",ans2);
    int o=0;
    for(int i=v2.size()-1;i>=0;i--)
    {
      if(o) printf(" => ");
      o++;
      printf("%d",v2[i]);
    }
    printf("\n");
  }
  else
  {
    printf("Time = %d: ",ans1);
    int o=0;
    for(int i=v1.size()-1;i>=0;i--)
    {
      if(o) printf(" => ");
      o++;
      printf("%d",v1[i]);
    }
    printf("\n");
    printf("Distance = %d: ",ans2);
    o=0;
    for(int i=v2.size()-1;i>=0;i--)
    {
      if(o) printf(" => ");
      o++;
      printf("%d",v2[i]);
    }
    printf("\n");
  }
  return 0;
}
