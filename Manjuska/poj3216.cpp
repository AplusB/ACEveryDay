#include<iostream>
#include<string.h>
using namespace std;

typedef class
{
public:
	int prime;
	int step;
}number;

bool JudgePrime(int digit)
{
	if (digit == 2 || digit == 3)
		return true;
	else if (digit <= 1 || digit % 2 == 0)
		return false;
	else if (digit>3)
	{
		for (int i = 3; i*i <= digit; i += 2)
			if (digit%i == 0)
				return false;
		return true;
	}
}

int a, b;
bool vist[15000];
number queue[15000];

void BFS(void)
{
	int i;  //temporary
	int head, tail;
	queue[head = tail = 0].prime = a;
	queue[tail++].step = 0;
	vist[a] = true;

	while (head<tail)
	{
		number x = queue[head++];
		if (x.prime == b)
		{
			cout << x.step << endl;
			return;
		}

		int unit = x.prime % 10;       
		int deca = (x.prime / 10) % 10;  

		for (i = 1; i <= 9; i += 2)     
		{
			int y = (x.prime / 10) * 10 + i;
			if (y != x.prime && !vist[y] && JudgePrime(y))
			{
				vist[y] = true;
				queue[tail].prime = y;
				queue[tail++].step = x.step + 1;
			}
		}
		for (i = 0; i <= 9; i++)     
		{
			int y = (x.prime / 100) * 100 + i * 10 + unit;
			if (y != x.prime && !vist[y] && JudgePrime(y))
			{
				vist[y] = true;
				queue[tail].prime = y;
				queue[tail++].step = x.step + 1;
			}
		}
		for (i = 0; i <= 9; i++)     
		{
			int y = (x.prime / 1000) * 1000 + i * 100 + deca * 10 + unit;
			if (y != x.prime && !vist[y] && JudgePrime(y))
			{
				vist[y] = true;
				queue[tail].prime = y;
				queue[tail++].step = x.step + 1;
			}
		}
		for (i = 1; i <= 9; i++)     
		for (i = 1; i <= 9; i++)     
		{
			int y = x.prime % 1000 + i * 1000;
			if (y != x.prime && !vist[y] && JudgePrime(y))
			{
				vist[y] = true;
				queue[tail].prime = y;
				queue[tail++].step = x.step + 1;
			}
		}

	}

	cout << "Impossible" << endl;
	return;
}

int main(void)
{
	int test;
	cin >> test;
	while (test--)
	{
		cin >> a >> b;
		memset(vist, false, sizeof(vist));
		BFS();
	}
	return 0;
}
