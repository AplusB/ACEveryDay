#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int se,re;
    char s[20],r[20];
    while(scanf("%s%d%d",s,&se,&re)>0)
    {
        int l=strlen(s),k=0,perc;

        long long sum=0;

        //先转化为10进制
        for(int i=0; i<l; i++)
        {
            if(s[i]>='0'&&s[i]<='9')
                sum=sum*se+s[i]-'0';
            else if(s[i]>='A'&&s[i]<='Z')
                sum=sum*se+s[i]-'A'+10;
        }

        //在转到b进制
        while(sum>0)
        {
            perc=sum%re;
            if(perc>=10)
                r[k++]=perc-10+'A';
            else
                r[k++]=perc+'0';
            sum=sum/re;
        }

        if(k>7)
            cout<<"  ERROR"<<endl;
        else
        {
            for(int j=0; j<7-k; j++)
                cout<<" ";
            for(int j=k-1; j>=0; j--)
                cout<<r[j];
            cout<<endl;
        }
    }
    return 0;
}
