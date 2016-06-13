

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
using namespace std;

int main()
{
	string s;
	vector<int> num;
	while(cin >> s)
	{
		int buf;
		for(int i=0;i<s.length();i++)
			if(s[i]=='5')
			s[i]=' ';

		stringstream ss(s);

		while(ss >> buf)
			num.push_back(buf);

		sort(num.begin(),num.end());

		for(vector<int>::iterator it=num.begin();it!=num.end();it++)
			if(it==num.begin())
				cout << *it;
			else	cout << ' ' << *it;

		cout << endl;

		ss.str("");

		vector <int>().swap(num);
	}
	return 0;
}
