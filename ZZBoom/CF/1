//CodeForces 688A

#include<cstdio>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

#define N 100010

int runnian(int n)
{
    if((!(n%400))||(!(n%4)&&n%100))
        return 1;
    return 0;
}
char ss[110][110];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%s",ss[i]);
    }
    int ans=0;
    int sum=0;
    for(int i=0;i<m;i++)
    {
        int flag=0;
        for(int j=0;j<n;j++)
        {
            int x=ss[i][j]-'0';
            if(x==0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            sum+=1;
        else
            sum=0;
        if(sum>ans)
            ans=sum;
    }
    printf("%d\n",ans);
    return 0;
}



//CodeForces 682A    
#include<cstdio>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

#define N 100010

int main()
{
    int i,n,m,num;
    cin>>n>>m;
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=(m+i)/5-i/5;
    }
    printf("%I64d\n",sum);
}

//CodeForces 678B    
#include<cstdio>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

#define N 100010

int runnian(int n)
{
    if((!(n%400))||(!(n%4)&&n%100))
        return 1;
    return 0;
}

int main()
{
    int n;
    cin>>n;

    int i,ans;
    ans=0;
    for(i=n+1;;i++)
    {
        if(runnian(i))
            ans+=2;
        else
            ans+=1;
        ans%=7;
        if(ans==0&&(runnian(n)==(runnian(i))))
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
