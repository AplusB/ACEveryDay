#include <bits/stdc++.h>
#define endl '\n'
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a > b ? b : a)

using namespace std;

const int MAXN = 105;

struct node
{
	char str[MAXN];
	int x;
}ans[1000005];

char str[MAXN];
int n;

int main()
{
	while(scanf("%d",&n) == 1)
	{
		priority_queue<int,vector<int>,greater<int> >que;
		
		int cont = 0;
		int i,x;
		for(i = 0;i < n;i++)
		{
			scanf("%s",str);
			if(str[0] == 'i')
			{
				scanf("%d",&x);
				//printf("%s %d\n",str,x);
				strcpy(ans[cont].str,"insert");
				ans[cont].x = x;
				cont++;
				que.push(x);
				//cout << que.size() << endl;	
			}
			else if(str[0] == 'r')
			{
				if(que.size() == 0)
				{
					strcpy(ans[cont].str,"insert");
					ans[cont].x = 1;
					que.push(1);
					cont++;
				}
				que.pop();
				strcpy(ans[cont].str,"removeMin");
				ans[cont].x = -1;
				cont++;
			}
			else if(str[0] == 'g')
			{
				scanf("%d",&x);
				int flag = 0;
				if(que.size() == 0)
				{
					strcpy(ans[cont].str,"insert");
					ans[cont].x = x;
					cont++; 
					que.push(x);
					flag = 1;
				}
				int temp = que.top();
				if(temp == x)
				{
					strcpy(ans[cont].str,str);
					ans[cont].x = x;
					cont++;
					continue;
				}
				
				while(temp < x && que.size() != 0)
				{
					strcpy(ans[cont].str,"removeMin");
					ans[cont].x = -1;
					cont++;
					que.pop();
					temp = que.top();
				}
				
				if(temp == x)
				{
					strcpy(ans[cont].str,str);
					ans[cont].x = x;
					cont++;
					continue;
				}
				
				if(flag == 0)
				{
					strcpy(ans[cont].str,"insert");
					ans[cont].x = x;
					cont++;
					que.push(x);
				}
				strcpy(ans[cont].str,str);
				ans[cont].x = x;
				cont++;
			}
		}
		
		cout << cont << endl;
		
		for(i = 0;i < cont;i++)
		{
			if(ans[i].str[0] == 'r')
			{
				printf("%s\n",ans[i].str);
			}
			else
			{
				printf("%s %d\n",ans[i].str,ans[i].x);
			}
		}
	}
	return 0;
}
