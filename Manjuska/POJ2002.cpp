#include<iostream>
#include<string.h>
using namespace std;
#define primer 1999
typedef struct
{
	int x, y;
}Node;
typedef struct HashTable
{
	int x, y;
	HashTable *next;
	HashTable()
	{
		next = 0;
	}
}HashTable;
Node pos[1001];
HashTable *hashTable [primer];

void insert_visit(int k)
{
	int key = ((pos[k].x*pos[k].x) + (pos[k].y*pos[k].y)) % primer + 1;
	if(!hashTable[key])
	{
		HashTable *temp =new HashTable;
		temp->x = pos[k].x;
		temp->y = pos[k].y;
		hashTable[key] = temp;
	}
	else
	{
		HashTable *temp=new HashTable ;
		//HashTable *temp2=new HashTable;
		while (temp->next)
			temp = temp->next;
		temp->next = new HashTable;
		temp->next->x = pos[k].x;
		temp->next->y = pos[k].y;
	}
	return;
}
bool find(int x,int y)
{
	int key = ((x*x) + (y*y)) % primer + 1;
	if (!hashTable[key])
		return false;
	else
	{
		HashTable *temp = hashTable[key];
		while(temp)
		{
			if(temp->x==x&&temp->y==y)
			{
				return true;
			}
			temp = temp->next;
		}
	}
}
int main(void)
{
	int n;
	while(cin>>n)
	{
		if(!n)
			break;
		memset(hashTable, 0, sizeof(hashTable));
		for(int k=1;k<=n;k++)
		{
			cin >> pos[k].x >> pos[k].y;
			insert_visit(k);
		}
		int num = 0;
		for (int i = 1; i <= n - 1; i++)
			for (int j = i + 1; j <= n; j++)
			{
				int a = pos[j].x - pos[i].x;
				int b = pos[j].y - pos[i].y;

				int x3 = pos[i].x + b;
				int y3 = pos[i].y - a;
				int x4 = pos[j].x + b;
				int y4 = pos[j].y - a;

				if (find(x3, y3) && find(x4, y4))
					num++;

				x3 = pos[i].x - b;
				y3 = pos[i].y + a;
				x4 = pos[j].x - b;
				y4 = pos[j].y + a;

				if (find(x3, y3) && find(x4, y4))
					num++;
			}

		cout << num << endl;
	}
	return 0;
}
