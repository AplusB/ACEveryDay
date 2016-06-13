#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int MAXN=20000;
int prime[MAXN+1];

//得到小于等于MAXN的素数，prime[0]存放的是个数
int getPrime()
{
    memset(prime,0,sizeof(prime));

    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i])
        {
        	prime[++prime[0]]=i;
        }

        for(int j=1 ; j<=prime[0]&&prime[j]<=MAXN/i ; j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
			{
				break;
			}
        }
    }
    return prime[0];
}

long long factor[100][2];
int facCnt;

//把x进行素数分解
int getFactors(long long x)
{
    facCnt=0;
    long long tmp=x;

    for(int i=1 ; prime[i]<=tmp/prime[i] ; i++)
    {
        factor[facCnt][1]=0;

        if(tmp%prime[i]==0)
        {
            factor[facCnt][0]=prime[i];

            while(tmp%prime[i]==0)
            {
                   factor[facCnt][1]++;
                   tmp/=prime[i];
            }

            facCnt++;
        }
    }

    if(tmp!=1)
    {
        factor[facCnt][0]=tmp;
        factor[facCnt++][1]=1;
    }
    return facCnt;
}


int main()
{
    int n;
    getPrime();
    int num;

    while(scanf("%d",&n)!=EOF)
    {
        int ans=0;
        int temp=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            if(num==1)//1的时候要单独处理一下
            {
                if(temp<1)
                {
                    temp=1;
                    ans=1;
                }
                continue;
            }

            getFactors(num);

            if(temp<factor[facCnt-1][0])
            {
                temp=factor[facCnt-1][0];
                ans=num;
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}
