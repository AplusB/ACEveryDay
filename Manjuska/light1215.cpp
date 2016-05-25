#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
long long lcm(long long a,long long b)
{
	return a*b / gcd(a, b);
}
int main()
{
	int T, num = 1;
	cin >> T;
	long long a, b, c, m, t, g, l;
	while(T--)
	{
		cin >> a >> b >> l;
		m = lcm(a, b);
		if(l%m!=0||m>l)
		{
			cout << "Case " << num++ << ": " << "impossible" << endl;
		}
		else
		{
			c = l / m;
			t = gcd(c, m);
			while(t!=1)
			{
				c = c*t;
				m /= t;
				t = gcd(c, m);
			}
			cout << "Case " << num++ << ": " << c << endl;
		}
	}
	return 0;
}
