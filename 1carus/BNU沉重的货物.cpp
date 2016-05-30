#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map>
#include <queue>
#include <string>
#define endl '\n'

using namespace std;

const int MAXN = 1005;

struct node{
	int x;
	node *next[55];
};

struct POINT{
	int x,v;
	const bool operator < (POINT old) const
	{
		return v < old.v;
	}
}p,q;

string s1,s2;
char str1[45],str2[45];
vector<POINT> g[MAXN];
int edge[MAXN][MAXN];
int n,r,cur;
int cnt,ant;
node *root;
 
node * create()
{
	node *p = new node();
	
	int i;
	for(i = 0;i < 26;i++)p -> next[i] = NULL;
	return p;
}
 
void insert(char *s,int x)
{
	node *p = root;
	
	int i,k;
	for(i = 0;s[i];i++)
	{
		k = s[i] - 'A';
		if(p -> next[k] == NULL)p -> next[k] = create();
		p = p -> next[k];
	}
	p -> x = x;
}
 
int search(char *s)
{
	node *p = root;
	
	int i,k;
	for(i = 0;s[i];i++)
	{
		k = s[i] - 'A';
		if(p -> next[k] == NULL)return 0;
		p = p -> next[k];
	}
	return p -> x;
}

int solve(int x,int y)
{
	int d[MAXN];
	int visit[MAXN];
	memset(visit,0,sizeof(visit));
	memset(d,0,sizeof(d));
	
	priority_queue<POINT> que;
	p.x = x;p.v = 0x3f3f3f3f;d[x] = 0x3f3f3f3f;
	que.push(p);
	while(!que.empty())
	{
		p = que.top();
		que.pop();
		if(visit[p.x])continue;
		visit[p.x] = 1;
		
		
		int i;
		for(i = 0;i < g[p.x].size();i++)
		{
			q = g[p.x][i];
			if(visit[q.x])continue;
			
			if(d[q.x] < min(d[p.x],q.v))
				d[q.x] = min(d[p.x],q.v);
				
			q.v = d[q.x];
			que.push(q);
		}
	}
	
	return d[y];
}

int main()
{
	int cont = 1;
	while(scanf("%d %d",&n,&r) == 2)
	{	
		root = create();
		cur = 0;
		
		if(n == r && r == 0)
		{
			break;
		}
		
		if(r == 0)
		{
			cout << "0 tons" << endl;
			continue;
		}
		
		int i,temp;
		for(i = 0;i <= n;i++)
		{
			g[i].clear();
		}
		
		for(i = 0;i < r;i++)
		{
			scanf("%s %s %d",str1,str2,&temp);
			int x,y;
			x = search(str1);
			y = search(str2);
			
			if(x == 0)insert(str1,x = ++cur);
			if(y == 0)insert(str2,y = ++cur);
			p.x = y;p.v = temp;
			
			g[x].push_back(p);
			p.x = x;
			g[y].push_back(p);
		}
		
		scanf("%s %s",str1,str2);
		int x = search(str1);
		int y = search(str2);
		
		printf("Scenario #%d\n",cont++);
		cout << solve(x,y);
		cout << " tons" << endl << endl;
	}
	return 0;
}
