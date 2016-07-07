//A

#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    int st,ed;
    scanf("%d",&n);
    int sum;
    sum=0;
    char s[15];
    int flag=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",s,&st,&ed);
        if(st>=2400&&ed>st)
        {
            flag=1;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
}


//B

#include<cstdio>
#include<map>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef long long LL;

int flag;

int main()
{
    LL n;
    scanf("%I64d",&n);
    LL sum;
    flag=0;
    for(LL i=0;i<=1000;i++)
    {
        if(i*1234567>n)
            break;
        for(LL j=0; j<=10000; j++)
        {
            if((j*123456+i*1234567)>n)
                break;
            if((n-j*123456-i*1234567)%1234==0)
                flag=1;
            if(flag)
                break;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
}

//C

#include<cstdio>
#include<map>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int> >qq;

struct asd{
    char s[10];
    int k;
};
asd q[500000];

int main()
{
    int n;
    scanf("%d",&n);
    int x;
    char ss[10];
    int num=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",&ss);

        if(ss[0]=='i')
        {
            scanf("%d",&x);
            strcpy(q[num].s,"insert");
            q[num].k=x;
            num++;
            qq.push(x);
        }
        else if(ss[0]=='r')
        {
            int s1,s2;
            if(!qq.empty())
            {
                s1=qq.top();
                strcpy(q[num].s,"removeMin");
                q[num].k=s1;
                num++;
                qq.pop();
            }
            else
            {
                strcpy(q[num].s,"insert");
                q[num].k=0;
                num++;

                strcpy(q[num].s,"removeMin");
                q[num].k=0;
                num++;
            }
        }
        else if(ss[0]=='g')
        {
            scanf("%d",&x);
            int s1;
            if(!qq.empty())
            {
                s1=qq.top();
                if(s1==x)
                {
                    strcpy(q[num].s,"getMin");
                    q[num].k=x;
                    num++;
                }
                else if(s1>x)
                {
                    strcpy(q[num].s,"insert");
                    q[num].k=x;
                    num++;
                    qq.push(x);

                    strcpy(q[num].s,"getMin");
                    q[num].k=x;
                    num++;
                }
                else if(s1<x)
                {
                    int flag=0;
                    while(!qq.empty())
                    {
                        int nn=qq.top();
                        if(nn==x)
                        {
                            strcpy(q[num].s,"getMin");
                            q[num].k=x;
                            num++;
                            break;
                        }
                        else if(nn>x)
                        {
                            strcpy(q[num].s,"insert");
                            q[num].k=x;
                            num++;
                            qq.push(x);

                            strcpy(q[num].s,"getMin");
                            q[num].k=x;
                            flag=1;
                            num++;
                            break;
                        }
                        else if(nn<x)
                        {
                            strcpy(q[num].s,"removeMin");
                            q[num].k=nn;
                            num++;
                            qq.pop();
                        }
                    }
                }
            }
            if(qq.empty())
            {
                strcpy(q[num].s,"insert");
                q[num].k=x;
                num++;
                qq.push(x);

                strcpy(q[num].s,"getMin");
                q[num].k=x;
                num++;
            }
        }
    }
    printf("%d\n",num);
    for(int i=0;i<num;i++)
    {
        if(q[i].s[0]=='r')
        {
            printf("%s\n",q[i].s);
        }
        else
        {
            printf("%s %d\n",q[i].s,q[i].k);
        }
    }
    return 0;
}
