//125B - Simple XML 

#include<stdio.h>
#include<iostream>
#include<cstdio>
#include<queue>
#include <vector>
#include<stack>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
using namespace std;
#define ll unsinged long long
#define PI acos(-1.0)
#define ING 0x7fffffff
#define INF 0x3f3f3f3f
#define DA 100005
#define N 1010
char s[N];
int main()
{
    while(~scanf("%s",s))
    {
        stack<char>q;
        int len=strlen(s);
        while(!q.empty())
            q.pop();
        int num;
        for(int i=0; i<len; i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                q.push(s[i]);
                num=i+1;
                break;
            }
        }
        int k,flag;
        printf("<%c>\n",s[num-1]);
        k=flag=0;
        int i;
        i=num;
        while(!q.empty()||i<len)
        {
        	char u;
        	if(!q.empty())
        		u=q.top();
            else
            	u='-1';
			for(i=num; i<len; i++)
            {
                if(s[i]>='a'&&s[i]<='z')
                {
                    if(s[i]!=u||(s[i]==u&&s[i-1]=='<'))
                    {
                        if(flag==0)
                        {
                            for(int j=1; j<=2*(k+1); j++)
                            {
                                printf(" ");
                            }
                            ++k;
                        }
                        else
                        {
                            for(int j=1;j<=2*k;j++)
                            {
                                printf(" ");
                            }
                        }
                        printf("<%c>\n",s[i]);
                        q.push(s[i]);
                        flag=0;
                    }
                    else
                    {
                        if(flag==0)
                        {
                            for(int j=1;j<=2*k;j++)
                                printf(" ");
                        }
                        else
                        {
                            for(int j=1;j<=2*(k-1);j++)
                            {
                                printf(" ");
                            }
                            --k;
                        }
                        printf("</%c>\n",s[i]);
                        q.pop();
                        flag=1;
                    }
                    num=i+2;
                    break;
                }
            }
        }
    }
    return 0;
}
