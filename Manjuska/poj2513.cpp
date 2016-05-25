#include<iostream>
#include<string.h>
using namespace std;
const int number = 500000;
class TrieTree_Node
{
public:
	bool flag;
	int id;
	TrieTree_Node *next[27];
	TrieTree_Node()
	{
		flag = false;
		id = 0;
		memset(next, 0, sizeof(next));
	}
}root;
int color = 0;
int degree[number + 1] = { 0 };
int ancestor[number + 1];

int find(int x)
{
	if (ancestor[x] != x)
		ancestor[x] = find(ancestor[x]);
	return ancestor[x];
}
void union_ser(int a,int b)
{
	int pa = find(a);
	int pb = find(b);
	ancestor[pb] = pa;
	return;
}
int hash_test(char *s)
{
	TrieTree_Node *p = &root;
	int len = 0;
	while(s[len]!='\0')
	{
		int index = s[len++] - 'a';
		if (!p -> next[index])
			p->next[index] = new TrieTree_Node;
		p = p->next[index];
	}
	if (p->flag)
		return p->id;
	else
	{
		p->flag = true;
		p->id = ++color;
		return p->id;
	}
}
int main(void)
{
	for (int k = 1; k <= number; k++)
		ancestor[k] = k;
	char a[11], b[11];
	while(cin>>a>>b)
	{
		int i = hash_test(a);
		int j = hash_test(b);
		degree[i]++;
		degree[j]++;
		union_ser(i, j);

	}
	int s = find(1);
	int num = 0;
	for(int i=1;i<=color;i++)
	{
		if (degree[i] % 2 == 1)
			num++;
		if (num>2)
		{
			cout << "Impossible" << endl;
			return 0;
		}

		if (find(i) != s)
		{
			cout << "Impossible" << endl;
			return 0;
		}

	}
	if (num == 1) 
		cout << "Impossible" << endl;
	else      
		cout << "Possible" << endl;
	return 0;
}
