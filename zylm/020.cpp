#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 100005
using namespace std;
struct Node
{
	string name;
	int before,after;
}node;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i,j,flag=0;
		for(i=0;i<n;i++)
		{
			cin>>node.name;
			cin>>node.before;
			cin>>node.after;
			
			if(node.before>=2400 && node.after>node.before)flag=1;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
