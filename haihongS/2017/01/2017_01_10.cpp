#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const int inf=2e9+9;
double eps=1e-6;
double pi=acos(-1.0);

struct II
{
	string name,sex,id;
	int score;
};

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		II m1,m2;
		m1.score=200,m2.score=-1;
		for(int i=0;i<n;i++)
		{
			II now;
			cin>>now.name>>now.sex>>now.id>>now.score;
			if(now.sex[0]=='M')
			{
				if(now.score<m1.score)	
					m1=now;
			}
			if(now.sex[0]=='F')
			{
				if(now.score>m2.score)
					m2=now;
			}
		}
		int flag=1;
		if(m2.score==-1 || m1.score==200) flag=0;

		if(m2.score==-1) cout<<"Absent\n";
		else cout<<m2.name<<" "<<m2.id<<"\n";

		if(m1.score==200) cout<<"Absent\n";
		else cout<<m1.name<<" "<<m1.id<<"\n";

		if(flag==0) cout<<"NA\n";
		else cout<<m2.score-m1.score<<"\n";

	}
	return 0;
}
