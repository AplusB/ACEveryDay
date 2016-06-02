#include<iostream>
#include<fstream>
#include<stdio.h>
#include<queue>
#include<string.h>
#define MAX 100005
using namespace std;
queue<int> q;
int step[MAX];
bool visit[MAX];
int n, k;
int Next, head;
int bfs()
{
	q.push(n);
	step[n] = 0;
	visit[n] = 1;
	while(!q.empty())
	{
		head = q.front();
		q.pop();
		for(int i=0;i<3;i++)
		{
			if (i == 0)
				Next = head - 1;
			else if (i == 1)
				Next = head + 1;
			else
				Next = head * 2;
			if(Next>MAX||Next<0)
				continue;
			if(!visit[Next])
			{
				q.push(Next);
				step[Next] = step[head] + 1;
				visit[Next] = 1;
			}
			if (Next == k)
				return step[Next];
		}
	}
	return -1;
}
int main()
{
	memset(visit, 0, sizeof(visit));
	scanf("%ld%ld", &n, &k);
	if (n >= k)
		printf("%d", n - k);
	else
		printf("%d", bfs());
	return 0;
}
