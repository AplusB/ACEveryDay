//lightoj	1198 - Karate Competition
#include<bits/stdc++.h>
using namespace std;
int ans1[200];
int ans2[200];
bool flag[200];
bool flag1[200];
typedef struct pp
{
    int x;
    int id;
    bool operator<(const pp &cx)const
    {
        return cx.x>x;
    }
} ss;
int er(int n,int m,int ak,int ac[]);
int main(void)
{
    int i,j,k;
    scanf("%d",&k);
    int s;
    int n,m;
    for(s=1; s<=k; s++)
    {
        scanf("%d",&n);
        priority_queue<ss>que;
        memset(flag,0,sizeof(flag));
        memset(flag1,0,sizeof(flag1));
        for(i=0; i<n; i++)
        {
            scanf("%d",&ans1[i]);
        }
        for(i=0; i<n; i++)
        {
            scanf("%d",&ans2[i]);
        }
        sort(ans1,ans1+n);
        sort(ans2,ans2+n);
        int sum=0;
        int uu=0;
        for(i=0;i<n;i++)
        {
            while(ans2[uu]<ans1[i]&&uu<n)
            {
                ss cc;
                cc.id=uu;
                cc.x=ans2[uu];
                que.push(cc);
                uu++;
            }
            if(!que.empty())
            {
                sum+=2;
                ss ak=que.top();
                que.pop();
                flag[i]=true;
                flag1[ak.id]=true;
            }
        } int ac[200];int vv=0;
        for(i=0;i<n;i++)
        {
            if(!flag[i])
            {
              for(j=0;j<n;j++)
              {
                  if(!flag1[j]&&ans1[i]==ans2[j])
                  {
                          sum+=1;
                          flag1[j]=true;
                          break;
                  }
              }
            }
        }
        printf("Case %d: %d\n",s,sum);
    }
    return 0;
}
