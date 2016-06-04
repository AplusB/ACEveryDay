#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
string s;
vector<int> v[10005];
bool vis[10005]={0};
queue<int> q;
int main()
{
  int n,m,k,x,t,y;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++)
  {
    scanf("%d %d",&x,&y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=0;i<k;i++)
  {
    memset(vis,0,sizeof(vis));
    scanf("%d",&x);
    while(!q.empty()) q.pop();
    q.push(x);
    while(!q.empty())
    {
      t=q.front();
      vis[t]=1;
      q.pop();
      for(int i=v[t].size()-1;i>=0;i--)
      {
        if(vis[v[t][i]]==0)
        q.push(v[t][i]);
      }
    }
    if(t==x) printf("0\n");
    else
    printf("%d\n",t);
  }
  return 0;
}
