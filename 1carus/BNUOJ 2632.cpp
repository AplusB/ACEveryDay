#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define N 500005
#define end '\n'
 
using namespace std;
 
struct node{
	int x;
	node *next[26];
};
 
int cnt,ant,p[N],deg[N];
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
		k = s[i] - 'a';
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
		k = s[i] - 'a';
		if(p -> next[k] == NULL)return 0;
		p = p -> next[k];
	}
	return p -> x;
}
 
void init()
{
	int i;
	for(i = 1;i <= N;i++)p[i] = i;
	cnt = 0;
	memset(deg,0,sizeof(deg));
}
 
int find(int x)
{
	if(x != p[x])p[x] = find(p[x]);
	return p[x];
}
 
void Union(int x,int y)
{
	p[y] = x;
}
 
bool judge()
{
	int i,k,odd = 0;
	for(i = 1;i <= cnt;i++)
	{
		if(deg[i] & 1)odd++;
	}
	if(odd != 0 && odd != 2)return false;
	
        //注意下面判断联通的方式。。。。
	k = find(1);
	for(i = 2;i <= cnt;i++)
	{
		if(k != find(i))return false;
	}
	return true;
}
int main()
{
	//freopen("in.in","r",stdin);
	char s1[15],s2[15];
	while(gets(s1))
	{
		int i;
		for(i = 0;i < strlen(s1);i++)
			{
				if(s1[i] == ' ')
				{
					s1[i] = '\0';
					i++;
					int j = 0;
					while(s1[i] != '\0')
					{
						s2[j++] = s1[i];
						i++;
					}
					s2[j] = '\0';
					break;
				}
			}
		init();
		ant = 0;
		root = create();
		
		int x,y,fx,fy;
		x = search(s1);
		y = search(s2);
		if(x == 0)insert(s1,x = ++cnt);
		if(y == 0)insert(s2,y = ++cnt);
		deg[x]++;
		deg[y]++;
		
		fx = find(x);
		fy = find(y);
		if(fx != fy)Union(fx,fy);
		while(gets(s1))
		{
			if(strlen(s1) == 0)break;
			int l;
			for(i = 0;i < strlen(s1);i++)
			{
				if(s1[i] == ' ')
				{
					s1[i] = '\0';
					i++;
					int j = 0;
					while(s1[i] != '\0')
					{
						s2[j++] = s1[i];
						i++;
					}
					s2[j] = '\0';
					break;
				}
			}
			
				x = search(s1);
				y = search(s2);
				if(x == 0)insert(s1,x = ++cnt);
				if(y == 0)insert(s2,y = ++cnt);
				deg[x]++;
				deg[y]++;
				
				fx = find(x);
				fy = find(y);
				if(fx != fy)Union(fx,fy);
		}
		
		if(judge())cout << "Possible" << endl;
		else cout << "Impossible" << endl;
	}
	return 0;
}
