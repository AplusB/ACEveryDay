#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2009;
const double eps=1e-9;


int a[maxn],up,use[maxn],gg[maxn];
char go[maxn],b[maxn],hou[maxn];
map<char,int> bb;
vector<char> aha;
stack<char>now;
stack<double> yy;
int flag,pos,n,m;

void dfs(int now);
int judge();

int main()
{
	
	while(scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		if(n==0 && m==0) break;
		scanf("%s",go);
		int len=strlen(go);
		
		while(!now.empty()) now.pop();
		aha.clear();
		bb.clear();
		
		for(int i=0;i<len;i++)
		{
			if('a'<=go[i] && go[i]<='z')
			{
				if(bb[go[i]]==0)
				{
					bb[go[i]]=1;
					aha.push_back(go[i]);
				}
			}
		}
		up=aha.size();
		
		pos=0;
		for(int i=0;i<len;i++)
		{
			if(go[i]=='(')
				now.push(go[i]);
			else if('a'<=go[i] && go[i]<='z')
				hou[pos++]=go[i];
			else if(go[i]==')')
			{
				while(!now.empty())
				{
					char tp=now.top();now.pop();
					if(tp=='(') break;
					hou[pos++]=tp;
				}
			}
			else if(go[i]=='+' || go[i]=='-')
			{
				while(!now.empty())
				{
					char tp=now.top();now.pop();
					if(tp=='(') {now.push(tp);break;}
					hou[pos++]=tp;
				}
				now.push(go[i]);
			}
			else if(go[i]=='*' || go[i]=='/')
			{
				while(!now.empty())
				{
					char tp=now.top();now.pop();
					if(tp=='(') {now.push(tp);break;}
					if(tp=='+' || tp=='-') {now.push(tp);break;}
					hou[pos++]=tp;
				}
				now.push(go[i]);
			}
		}
		while(!now.empty())
		{
			char tp=now.top();now.pop();
			hou[pos++]=tp;
		}
		flag=0;
		memset(use,0,sizeof(use));
		dfs(0);
		
		if(flag) printf("YES\n");
		else printf("NO\n");
	
				
	}
	return 0;
}

int judge()
{
	while(!yy.empty()) yy.pop();
	for(int i=0;i<pos;i++)
	{
		if('a'<=hou[i] && hou[i]<='z')
		{
			yy.push(1.0*a[gg[hou[i]-'a']]);
		}
		else
		{
			double a=1.0*yy.top();yy.pop();
			double b=1.0*yy.top();yy.pop();
			double c;
			if(hou[i]=='+') c=a+b;
			else if(hou[i]=='-') c=b-a;
			else if(hou[i]=='*') c=a*b;
			else if(hou[i]=='/') c=b/a;
			yy.push(c);
		}
	}
	double v=yy.top();yy.pop();
	if(fabs(v-1.0*m)<eps) flag=1;
	return 0;	
}

void dfs(int now)
{
	if(flag==1) return ;
	if(now==up)
	{ 
		judge();return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(use[i]==0)
		{
			use[i]=1;
			gg[aha[now]-'a']=i;
			dfs(now+1);			
			use[i]=0;
		}
		if(flag) return ;
	}
	return ;
}
