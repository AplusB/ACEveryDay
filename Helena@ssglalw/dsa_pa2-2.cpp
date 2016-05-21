#include <cstdio>
using namespace std;
const int MAX_N = 4000005;

int n;
int pre[MAX_N];
int post[MAX_N];
int in[MAX_N];

struct Stack{
	int _elem[MAX_N];
	int size;
	Stack():size(0){}
	void push(int x){
		_elem[size++] = x;
	}
	int top(){
		return _elem[size-1];
	}
	int pop(){
		return _elem[--size];
	}
	bool empty(){
		return !size;
	}
}root;

struct Node{
	int data;
	Node *lc, *rc;
};

void get_in(int pre_s, int pre_e, int post_s, int post_e){//
//	printf("%d %d %d %d\n", pre_s, pre_e, post_s, post_e);
	if(pre_s == pre_e){
		printf("%d ", pre[pre_s]);
		return ;//抵达叶节点
	}
	int i = pre_s + 1;
	int j = post_s;
	while(pre[i] != post[j]){
		j++;
	}
	int a = j;
	j = post_e - 1;
	i = pre_e;
	while(pre[i] != post[j]){
		i--;
	}
	int b = i;
	get_in(pre_s+1, b-1, post_s, a);
	printf("%d ", pre[pre_s]);
	get_in(b, pre_e, a+1, post_e-1);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &pre[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &post[i]);
	}
	
	get_in(0, n-1, 0, n-1);
	printf("\n");
	return 0;
}
