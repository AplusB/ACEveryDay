#include <cstdio>
#include <string>
#include <iostream>
#define MAX_N 100009
using namespace std;

struct Node{
	string s;
	int times;
	Node* next;
	Node():s(""), times(0), next(NULL){}
	Node(string ss):s(ss), times(1), next(NULL){}
};

struct HashTable{
	Node* table[100009];
	int factor[40];
	int N;//地址数
	HashTable():N(100009){}
	void initFactor(){
		int p = 1;
		factor[0] = p;
		int base = 33;
		for(int i=1; i<sizeof(factor); i++){
			p = ((p%N)*base)%N;
			factor[i] = p;
		}
	}
	int getAddress(string s){
		int ans = 0;
		int base = 0;
		int a = 33;
		for(int i=0; i<s.length(); i++){
			int item = ((s[i]-'a') * (factor[i]%N)) % N;
			ans = (ans + item) % N;
		}
		return ans;
	}
	void insert(string s){
		//cout << "insert " << s << " at ";
		int address = getAddress(s);
		//cout << address << endl;
		if(table[address] == NULL){
			table[address] = new Node(s);
		}else{
			Node* cur = table[address];
			while(cur && cur->s != s) cur = cur->next;
			if(cur){
				(cur->times)++;
				if(cur->times == 2)
					cout << cur->s << endl;
			}else{
				cur->next = new Node(s);
			}
		}
	}
	void printFactor(){
		for(int i=0; i<40; i++){
			cout << factor[i] << " ";
		}
		cout << endl;
	}
};

HashTable hs;

int main()
{
	int n;
	//freopen("pa3-2.txt", "r", stdin);
	cin >> n;
	hs.initFactor();
	//hs.printFactor();
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		//cout << i << endl;
		hs.insert(s);
	}
	return 0;
}
