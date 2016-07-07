//POJ3273

#include<cstdio>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 100010

int n,m;
int val[N];

int main()
{
    int sum=0;
    int Tmax=0;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val[i]);
            if(val[i]>Tmax)
                Tmax=val[i];
            sum+=val[i];
        }
        int Low=Tmax;
        int High=sum;
        int cnt,mid;

        while(Low<=High)
        {
            mid=(Low+High)/2;

            sum=0;
            cnt=1;
            for(int i=0;i<n;i++)
            {
                sum+=val[i];
                if(sum>mid)
                {
                    sum=val[i];
                    cnt++;
                }
            }
            if(cnt<=m)
            {
                Tmax=mid;
                High=mid-1;
            }
            else
                Low=mid+1;
        }
        printf("%d\n",Tmax);
    }

    return 0;
}




