#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
char a[105],b[105];
int ans[105];
stack<char> stk;
int main()
{
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		int i=0,j=0,t=0;
		scanf("%s",a);
		scanf("%s",b);
		while(!stk.empty())
			stk.pop();
	while(j<m)
	{
		if((stk.empty()||stk.top()!=b[j])&&i<m)
		{
			stk.push(a[i++]);
			ans[t++]=0;
		}
		else
		{
			if(stk.top()==b[j])
			{
				stk.pop();
				j++;
				ans[t++]=1;
			}
			else
			break;
		}
	}
	if(j==m)
	{
		printf("Yes.\n");
	for(int i=0;i<t;i++)
		printf("%s\n",ans[i]==0?"in":"out");
	}
	else
		printf("No.\n");
	printf("FINISH\n");
	}
	return 0;
}
