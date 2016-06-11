#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[20] = {2,3,4,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49};
	int cnt = 0;
	for(int i=0;i<19;i++){
		cout<<a[i]<<"\n";
		cout<<flush;
		string s;
		cin>>s;
		if(s=="yes")	cnt++;
	}
	if(cnt>=2)	cout<<"composite";
	else cout<<"prime";
	return 0;
}
