#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int s[123];
int a[123];
int last[123];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    while(~scanf("%d",&n))
	{
        int alice=0,bob=0;
        int half,cnt=0;
        int get = 0;

        for(int i=0;i<n;i++)
		{
            scanf("%d",&s[i]);

            for(int j=0;j<s[i];j++)
			{
                scanf("%d",&a[j]);
            }
            half = s[i]/2;

            //一人一半
            if(s[i]%2==0)
			{
                for(int j=0;j<half;j++)
                {
                    alice+=a[j];
                    get++;
                }
                for(int j=half;j<s[i];j++)
				{
                    bob+=a[j];
                    get++;
                }
            }

            //剩了一个
            else
			{
                for(int j=0;j<half;j++)
                {
                    alice+=a[j];
                    get++;
                }

                last[cnt++] = a[half];

                for(int j=half+1;j<s[i];j++)
                {
                    bob+=a[j];
                    get++;
                }
            }
        }

        if(cnt!=0)
		{
            sort(last,last+cnt,cmp);
            //alice first
            if(get%2==0)
			{
                for(int i=0;i<cnt;i++)
                {
                    if(i%2==0)
                    {
                        alice+=last[i];
                    }
                    else
                    {
                        bob+=last[i];
                    }
                }
            }

            //bob first
            else
			{
                for(int i=0;i<cnt;i++)
                {
                    if(i%2==1)
                    {
                        alice+=last[i];
                    }
                    else
                    {
                        bob+=last[i];
                    }
                }
            }
        }

        printf("%d %d\n",alice,bob);
    }
    return 0;
}
