#include<iostream>

#define VNUM 101
#define MAXCOST 10000

using namespace std;

int edges[VNUM][VNUM]={};
int lowcost[VNUM];
bool visited[VNUM];
int vertices[VNUM];
int totalcost;
int minv;

int prim(int vnum,int v)
{
	totalcost=0;
	int i;
	int j;
	int k=0;
	visited[v]=true;

	for(i=0; i < vnum; i++)
	{
		lowcost[i]=edges[v][i];
	}

	for(i=1;i< vnum;i++)
	{
		minv=MAXCOST;

		for(j=0;j<vnum;j++)
		{
			if(visited[j]==false&&lowcost[j]<minv)
			{
				minv=lowcost[j];
				v=j;
			}
		}

		visited[v]=true;
		totalcost+=minv;

		for(j=0;j<vnum;j++)
		{
			if(visited[j]==false&&edges[v][j]<lowcost[j])
			{
				lowcost[j]=edges[v][j];
			}
		}
	}
	return totalcost;
}

int main()
{
	int num,degree,i,j,a,b,cost;
	while(cin>>num&&num)
	{
		for(i=0;i<num;i++)
		{
			for(j=0;j<num;j++)
			{
				edges[i][j]=MAXCOST;
			}
		}
		for(i=0;i<num*(num-1)/2;i++)
		{
			cin>>a>>b>>cost;
			edges[a-1][b-1]=cost;
			edges[b-1][a-1]=cost;
		}
		for(i=0;i<num;i++)
			visited[i]=false;
		for(i=0;i<num;i++)
			vertices[i]=i;
		cout<<prim(num,0)<<endl;
	}
	return 0;
}
