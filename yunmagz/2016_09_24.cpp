//ACM-ICPC国际大学生程序设计竞赛北京赛区(2016)网络赛
//A	The Book List
#include<bits/stdc++.h>
using namespace std;
typedef struct TNode *FK;
struct TNode
{
    char name[261];
    int flag;
    int front;
    FK next[100];
};

char str[261];

int find(char *s,char *str)
{
    int pos=0;
    str[0]='\0';
    int n=strlen(s);
    for(pos=0; pos<n; pos++)
    {
        if(s[pos]=='/')
            break;
    }
    if(pos==n)
    {
        strcpy(str,s);
        s[0]='\0';
        return -1;
    }
    int i;
    for(i=0; i<pos; ++i)
    {
        str[i]=s[i];
    }
    str[pos]='\0';
    if(pos==n-1)
        s[0]='\0';
    else
    {
        int cnt=0;
        for(i=pos+1; i<n; ++i)
        {
            s[cnt++]=s[i];
        }
        s[cnt]='\0';
    }

    return pos;
}

FK insertTree(char *s,FK root)
{
    int pos=find(s,str);
    //cout<<str<<endl;
    FK tmp=(FK)malloc(sizeof(struct TNode));
    strcpy(tmp->name,str);
    tmp->flag=0;
    tmp->front=0;
    if(pos==-1)
        tmp->flag=1;
    int i;
    // cout<<strlen(s)<<endl;
    for(i=0; i< root->front; i++)
    {
        if(strcmp((root->next)[i]->name,tmp->name)==0 && !(root->next)[i]->flag && !tmp->flag)
        {
            if(strlen(s)>0)
                root->next[i]=insertTree(s,root->next[i]);
            break;
        }
    }

    if(i==root->front)
    {
        root->next[root->front]=tmp;
        root->front++;
        if(strlen(s)>0)
            tmp=insertTree(s,tmp);
    }

    return root;
}

void maopao(FK root,FK tmp)
{
    //cout<<root->front<<endl;
    if(root->front)
    {
        for(int i=0; i<root->front; ++i)
            maopao(root->next[i],tmp);
        for(int i=0; i<root->front; ++i)
        {
            for(int j=0; j<root->front; ++j)
            {
                int a=root->next[i]->flag;
                int b=root->next[j]->flag;
                if(!a && b)
                {
                    // swap(root->next[i],root->next[j]);
                    tmp=root->next[i];
                    root->next[i]=root->next[j];
                    root->next[j]=tmp;
                }
                else if((a&&b) ||(!a&&!b) )
                {
                    if(strcmp(root->next[i]->name,root->next[j]->name)<0)
                    {
                        //swap(root->next[i],root->next[j]);
                        tmp=root->next[i];
                        root->next[i]=root->next[j];
                        root->next[j]=tmp;
                    }
                }
            }

        }

    }
}

bool cnt;
void print(FK root,int kg)
{
    for(int i=0; i<kg; i++)
        printf(" ");
    if(cnt)
    {
        printf("%s\n",root->name);
        kg+=4;
    }
    cnt=1;
    for(int i=0; i<root->front; ++i)
        print(root->next[i],kg);
    kg-=4;
}

map<string,int >mp;

int main()
{
    char s[261];
    FK root=(FK)malloc(sizeof(struct TNode));
    strcpy(root->name,"root");
    root->flag=0;
    root->front=0;
    cnt=0;
    mp.clear();
    int casee=1;
    while(gets(s))
    {
        //scanf("%s",s);
        if(strcmp(s,"0")==0)
        {
            printf("Case %d:\n",casee++);
            FK tmp=(FK)malloc(sizeof(struct TNode));
            tmp=NULL;
            maopao(root,tmp);
            int t=0;
            print(root,t);
            cnt=0;

            mp.clear();

            //free(root);
            /*FK root=(FK)malloc(sizeof(struct TNode));
            strcpy(root->name,"root");*/
            root->flag=0;
            root->front=0;
            continue;
        }
        if(!mp[s])
        {
            mp[s]=1;
            root=insertTree(s,root);
        }

    }

    return 0;
}
//C	A Simple Job
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair< PI, int> PII;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int MAXN = 800000;
const int MAXM = 20100;

map<string,int >mp;
//pair<string,int >pp;

int main()
{
    string tmp;
    string ss;
    string s;
    mp.clear();
    while(getline(cin,ss))
    {
        if(ss=="####")
        {
            //sort(mp.begin(),mp.end(),cmp);
            int sum=0;
            for(auto i=mp.begin(); i!=mp.end(); ++i)
            {
                if(i->second>sum)
                    sum=i->second;
            }
            string tt="";
            for(auto i=mp.begin(); i!=mp.end(); ++i)
            {
                if(i->second==sum)
                {
                    if(tt=="")
                        tt=i->first;
                    else
                    {
                        if(i->first<tt)
                        {
                            tt=i->first;
                        }
                    }
                }
            }
            cout<<tt<<":"<<sum<<endl;
            mp.clear();
            continue;
        }
        int len=ss.size();
        s.clear();
        bool flag=0;
        s.push_back(' ');
        for(int i=0; i<len; ++i)
        {
            if(ss[i]==' ' && !flag)
            {
                flag=1;
                s.push_back(ss[i]);
            }
            else if(ss[i]!=' ')
            {
                flag=0;
                s.push_back(ss[i]);
            }
        }

        len=s.size()-1;
        //cout<<s<<endl;
        for(int i=1; i<len; ++i)
        {
            if(s[i]==' ')
            {
                if(s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z')
                {
                    int ti=i-1;
                    int tj=i+1;
                    while(ti>0 && s[ti]>='a' && s[ti]<='z')
                    {
                        ti--;
                    }
                    ti++;
                    while(tj<s.size() && s[tj]>='a' && s[tj]<='z')
                    {
                        tj++;
                    }
                    //cout<<ti<<" "<<i-ti<<endl;
                    tmp=s.substr(ti,i-ti);
                    tmp+=s.substr(i,tj-i);
                    mp[tmp]++;
                }
            }


        }


    }




    return 0;
}
//F	Periodic Signal
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
struct node
{
    int id;
    LL v;
}a[60010];
bool cmp(node a,node b)
{
    return a.v>b.v;
}
LL b[60010],c[60010];
LL solve(int n){
    LL mx=0;
    int tmp;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&b[i]);
        if(b[i]>mx)
        {
            mx=b[i];
            tmp=i;
        }
    }
    sort(a,a+n,cmp);
    int m=min(n,10000);
    LL ans=1e18;
    for(int i=0;i<m;i++)
    {
        int k=tmp+n-a[i].id;
        if(k>=n) k-=n;
        LL res=0;
        for(int j=0;j<n;j++)
        {
            int g=j+k;
            if(g>=n) g-=n;
            res+=(c[j]-b[g])*(c[j]-b[g]);
            if(res>ans) break;
        }
        ans=min(ans,res);
    }
    return ans;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i].v);
            a[i].id=i;
            c[i]=a[i].v;
        }
        printf("%lld\n",solve(n));
    }
    return 0;
}
