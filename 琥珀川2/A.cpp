#include<iostream>
#include<queue>
#include<stack>
#include<stdio.h>
using namespace std;

char op[5];

int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int num;

		priority_queue<int,deque<int>,greater<int> >q;
		while(!q.empty())q.pop();

		for(int z=0;z<n;z++)
		{
			scanf("%s",op);

		if(op[0]=='I')
		{
			scanf("%d",&num);
			if(q.size()<k)
				q.push(num);
			else if(q.top()<num)
			{
				q.pop();
				q.push(num);
			}
		}
		else
			printf("%d\n",q.top());
		}

	}
	return 0;
}
