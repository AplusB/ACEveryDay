/* ***********************************************
Author        :guanjun
Created Time  :2016/7/1 22:14:21
File Name     :1338.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10000+10
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
 
bool cmp(int a,int b){
    return a>b;
}
char s1[200],s2[200];
string doit(int len,char *s){
    string ss="";
    vector<char>v;
    for(int i=0;i<len;i++){
        if(s[i]!=' '){
            if(s[i]<='Z'&&s[i]>='A'){
                s[i]=char(s[i]+32);
            }
            v.push_back(s[i]);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        ss+=v[i];
    }
    return ss;
}
int work(char *s1,char *s2){
    int len1=strlen(s1);
    int len2=strlen(s2);
    string s3,s4;
    s3=doit(len1,s1);
    s4=doit(len2,s2);
    if(s4.size()<s3.size())return 0;
    int num=0,mark=0;
    for(int i=0;i<s4.size();i++){
        for(int j=0;j<s3.size();j++){
            if(s3[j]==s4[i]){
                num=0;
                for(int k=j;k<s3.size();k++){
                    if(s3[k]==s4[k]){
                        num++;
                    }
                    else break;
                }
                if(num==s3.size()){
                    mark=1;break;
                }
            }
        }
        if(mark)break;
    }
    if(mark)return 1;
    return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    getchar();
    for(int i=1;i<=t;i++){
        gets(s1);
        gets(s2);
        if(work(s1,s2)){
            printf("Case %d: Yes\n",i);
        }
        else{
            printf("Case %d: No\n",i);
        }
    }
    return 0;
}
