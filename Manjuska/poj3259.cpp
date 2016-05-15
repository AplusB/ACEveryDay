
#include <stdio.h>  
  
#define maxN 502  
#define maxM 2702  
#define inf 1000000000  
  
struct EDGE   
{  
    int u,v,w;  
}edge[2 * maxM];  
int dis[maxN];  
  
int N, M, W;  
int edgeNum;  
  
void Init()  
{  
    for (int i = 0; i <= N; ++ i)  
    {  
        dis[i] = inf;  
    }  
}  
  
bool bellMan(void)  
{  
    bool flag;  
    for (int i = 0; i < N - 1; ++ i)  
    {  
        flag = false;  
        for (int j = 0; j < edgeNum; ++ j)  
        {  
            if (dis[edge[j].v] > dis[edge[j].u] + edge[j].w)//松弛  
            {  
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w;  
                flag = true;  
            }  
        }  
        if (!flag)//存在负权回路  
        {  
            break;  
        }  
    }  
    for (int i = 0; i < edgeNum; ++ i)  
    {  
        if(dis[edge[i].v] > dis[edge[i].u] + edge[i].w)  
            return true;  
    }  
    return false;  
}  
  
int main()  
{  
    int F;  
    scanf("%d", &F);  
    while (F --)  
    {  
        scanf("%d%d%d", &N, &M, &W);  
        edgeNum = 0;  
        Init();  
        int u,v,w;  
        for (int i = 1; i <= M; ++ i)  
        {  
            scanf("%d%d%d", &u, &v, &w);//正权双向  
            edge[edgeNum].u = u;  
            edge[edgeNum].v = v;  
            edge[edgeNum].w = w;  
            edgeNum ++;  
            edge[edgeNum].u = v;  
            edge[edgeNum].v = u;  
            edge[edgeNum].w = w;  
            edgeNum ++;  
        }  
        for (int i = 1; i <= W; ++ i)  
        {  
            scanf("%d%d%d", &u, &v, &w);  
            edge[edgeNum].u = u;  
            edge[edgeNum].v = v;  
            edge[edgeNum].w = -w;//负权  
            edgeNum ++;  
        }  
        if(bellMan())    
            printf("YES\n");  
        else    
            printf("NO\n");  
  
    }  
    return 0;  
}  
