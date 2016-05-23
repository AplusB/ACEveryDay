#include<iostream>
using namespace std;
int max(int a,int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int **way = new int*[n + 1];
		for(int i=0;i<=n;i++)
		{
			way[i] = new int[i + 2];
			for (int j = 0; j <= i + 1; j++)
				way[i][j] = 0;
			if (i != 0)
				for (int j = 1; j <= i; j++)
					cin >> way[i][j];
		}
		int max_height = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
			{
				way[i][j] += max(way[i - 1][j - 1], way[i - 1][j]);
				if (i == n && max_height < way[i][j])
					max_height = way[i][j];
			}
		cout << max_height << endl;
		delete[] way;
	}
	return 0;
}
