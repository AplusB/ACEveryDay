#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <vector>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int maxn=100004;  
struct node{  
    int to,w;  
    node(int a=0,int b=0){to=a;w=b;}  
};  
int f[maxn],dis[maxn],n,ans[maxn],vis[maxn];  
int val[maxn];
//f[i]并查集所用，记录前继结点  
//dis[i]记录个点到跟结点的距离  
//ans记录m个询问的答案  
//vis标记查询过了的点  
vector<node>e[maxn];//记录树  
vector<node>q[maxn];//记录所求最短距离的两点  
int find(int x)  
{  
    if(x!=f[x])f[x]=find(f[x]);  
    return f[x];  
}  
void lca(int u)  
{  
    int i,j,k,v,c;  
    for(i=0;i<e[u].size();i++)  
    {  
        v=e[u][i].to;  
        if(vis[v])continue;  
        vis[v]=1;  
        dis[v]=dis[u]+e[u][i].w;  
        lca(v);//深度优先搜索  
        f[v]=u;  
        for(j=0;j<q[v].size();j++)  
        {  
            c=q[v][j].to;  
            //如果所求两点中的对应点已知，则必定在同一子树上，由于并查集只记录所在子树。所以find(c)，就是最近公共祖先  
            if(vis[c]&&ans[q[v][j].w]==-1)  
            {  
                if(v==c)ans[q[v][j].w]=0;//自成环  
                else ans[q[v][j].w]=dis[v]+dis[c]-2*dis[find(c)];  
            }  
        }  
    }  
}  

int gcd(int a,int b)
{
	if(b == 0)return a;
	else return gcd(b,a % b);
}

int main()  
{   
    while(scanf("%d",&n) == 1)  
    {  
        int i,j,k,a,b,c,m,aa,bb;  
        
        for(i = 1;i <= n;i++)
        {
        	scanf("%d",&val[i]);
		}
		
        for(i=1;i<=n;i++)  
        {  
            e[i].clear();  
            q[i].clear();  
            ans[i]=-1;  
            f[i]=i;  
            vis[i]=0;  
        }  
        for(i=1;i<n;i++)  
        {  
            scanf("%d%d",&a,&b);  
            e[a].push_back(node(b,1));  
            e[b].push_back(node(a,1));  
        } 
        int cur = 0;
        for(i=1;i<=n;i++)  
        {  
        	for(j = i + 1;j <= n;j++)
        	{
        		if(gcd(val[i],val[j]) != 1)continue;
	            q[i].push_back(node(j,cur));  
	            q[j].push_back(node(i,cur));
				cur++;  
			}
        }  
        vis[1]=1;  
        dis[1]=0;  
        lca(1);  
        long long sum = 0;
        for(i=0;i<cur;i++)sum += ans[i];
        cout << sum << endl; 
    }  
    return 0;  
}  
