#include<iostream>
#include <stdio.h>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <string.h>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
string s;
int num[25];
int main()
{
        int ans,bns,t,a;
    while(cin>>s)
    {
            bool flagL=0,flagM=0;
            scanf("%d",&a);
            t=1;
            ans=num[0]=s[0]-'0';
        for(int i=1;i<s.size();i+=2)
        {
                if(s[i]=='+')
                {
                        ans+=s[i+1]-'0';
                        num[t++]=s[i+1]-'0';
                }
                else
                {
                        ans*=s[i+1]-'0';
                        num[t-1]*=s[i+1]-'0';
                }
        }
        int bns=0;
        if(ans==a)  flagL=1;
        for(int i=0;i<t;i++)
                bns+=num[i];
        if(bns==a) flagM=1;
        if(flagL==1&&flagM==1) printf("U\n");
        else if(flagL==1) printf("L\n");
        else if(flagM==1) printf("M\n");
        else printf("I\n");
    }
    return 0;
}
