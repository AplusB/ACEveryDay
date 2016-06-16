#include<cstdio>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

string getss(const string& str)
{
    int len=str.size();
    if(len<=1)
        return str;
    vector<char>vv;
    vv.clear();
    for(int i=0;i+1<len;i++)
    {
        if(str[i]==str[i+1])
        {
            while(i+1<len&&str[i]==str[i+1])
                i++;
        }
        else
            vv.push_back(str[i]);
    }
    if(str[len-2]!=str[len-1])
        vv.push_back(str[len-1]);

    return string(vv.begin(),vv.end());
}


int main()
{
    int n;
    string ss;
    cin>>n;
    string cc="ABC";
    while(n--)
    {
        cin>>ss;
        int Tmax=ss.size();
        int Tmin=ss.size();
        string tt;
        for(int i=0;i<ss.size();i++)
        {
            for(int j=0;j<3;j++)
            {
                string str=ss.substr(0,i+1)+cc[j]+ss.substr(i+1);
                int len=str.size();

                while(len>(str=getss(str)).size())
                {
                    len=str.size();
                    tt=str;
                }
                if(Tmin>str.size())
                    Tmin=str.size();

            }
        }
        printf("%d\n",Tmax-Tmin+1);
    }
    return 0;
}


