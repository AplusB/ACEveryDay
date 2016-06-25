#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int ans=0;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
		ans+=s[i]-'0';
	vector<int>vt;
	if(ans==0)
		vt.push_back(0);
	else
	{
		while(ans>0)
		{
			vt.push_back(ans%10);
			ans/=10;
		}
	}
	int f=0;
	for(int i=vt.size()-1;i>=0;i--)
	{
		if(f) printf(" ");
		else f++;
		if(vt[i]==0) printf("zero");
		else if(vt[i]==1) printf("one");
		else if(vt[i]==2) printf("two");
		else if(vt[i]==3) printf("three");
		else if(vt[i]==4) printf("four");
		else if(vt[i]==5) printf("five");
		else if(vt[i]==6) printf("six");
		else if(vt[i]==7) printf("seven");
		else if(vt[i]==8) printf("eight");
		else if(vt[i]==9) printf("nine");
	}
	printf("\n");
	return 0;
}
