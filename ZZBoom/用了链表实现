//poj 1528
//2333333  题目超级水，但是！刚学了链表拿来high一high也不错啊。 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;
#define INF 0x3f3f3f
#define pi acos(-1.0)
#define LL long long
#define N 550
typedef struct student* STU;
#define LENTH sizeof(struct student)
#define null 0
struct student{
	int data;
	STU next;
};

STU creat_list(STU head)
{
	STU p,q;
	head=p=(STU)malloc(LENTH);
	p->next=null;
	q=p;
	int x;
	while(cin>>x)
	{
		q->next=p;
		p->data=x;		
		q=p;
		q->next=null;
		if(x==0)
			break;
		p=(STU)malloc(LENTH);
	}
	return head;
}
void print(STU head)
{
	STU p;
	p=head;
	int i,sum,n;
	while(p!=null)
	{
		n=p->data;
		if(n==0) break;
		else if(n==1) printf("%5d  DEFICIENT\n",n);
		else 
		{
			sum=1;
			for(i=2;i<n;i++){
				if(n%i==0)
					sum+=i;
			}
			if(sum<n) printf("%5d  DEFICIENT\n",n);
			else if(sum==n) printf("%5d  PERFECT\n",n);
			else printf("%5d  ABUNDANT\n",n);
		}
		p=p->next;
	}
}

int main()
{
	STU head;
	head=creat_list(head);
	cout<<"PERFECTION OUTPUT"<<endl;
	print(head);
	cout<<"END OF OUTPUT"<<endl;
}
