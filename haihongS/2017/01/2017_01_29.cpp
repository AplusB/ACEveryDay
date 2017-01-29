#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const ll mod=1e9+7;
const ll inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

int z[5][10]={
{7,4,1,8,5,2,9,6,3},
{9,8,7,6,5,4,3,2,1},
{3,6,9,2,5,8,1,4,7}
};
int ff[5][10]={
{7,8,9,4,5,6,1,2,3},
{3,2,1,6,5,4,9,8,7}
};
queue<string> aha;
vector<string> go,ans;
map<string,int>use;

string rotate(string x,int p);
string flip(string x,int p);
void pre();

int main()
{
	pre();
	ans.clear();
	string now="";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			int x;
			scanf("%d",&x);
			now+=x+'0';
		}
	}
	int len=go.size();
	for(int i=0;i<len;i++)
	{
		string tmp=go[i];
		int ok=1;
		for(int j=0;j<9;j++)
		{
			if(now[j]=='0') continue;
			if(now[j]!=tmp[j]) 
			{
				ok=0;break;
			}
		}
		if(ok) ans.push_back(tmp);
	}
	if(ans.size()>1) printf("Too Many\n");
	else
	{
		string tmp=ans[0];
		for(int i=0;i<9;i++)
		{
			if(i%3==0) printf("%c",tmp[i]);
			else if(i%3==1) printf(" %c",tmp[i]);
			else printf(" %c\n",tmp[i]);
		}
	}
	return 0;
}

void pre()
{
	while(!aha.empty()) aha.pop();
	use.clear();
	go.clear();
	string pri="492357816";
	aha.push(pri);
	go.push_back(pri);
	use[pri]=1;
	while(!aha.empty())
	{
		string tp=aha.front();aha.pop();
		for(int i=0;i<3;i++)
		{
			string tmp=rotate(tp,i);
			if(use[tmp]==1) continue;
			use[tmp]=1;
			aha.push(tmp);
			go.push_back(tmp);
		}
		for(int i=0;i<2;i++)
		{
			string tmp=flip(tp,i);
			if(use[tmp]==1) continue;
			use[tmp]=1;
			aha.push(tmp);
			go.push_back(tmp);
		}
	}
}

string flip(string x,int p)
{
	string now="";
	for(int i=0;i<9;i++)
	{
		now+=x[ff[p][i]-1];
	}
	return now;
}

string rotate(string x,int p)
{
	string now="";
	for(int i=0;i<9;i++)
	{
		now+=x[z[p][i]-1];
	}
	return now;
}
