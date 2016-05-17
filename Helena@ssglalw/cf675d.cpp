#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
const int MAX_N = 100005;

int n;
struct Node
{
	int d;
	int lc, rc;
	Node(){}
	Node(int d):d(d), lc(-1), rc(-1){}
}nodes[MAX_N];

int a[MAX_N];

int main()
{
	while(~scanf("%d", &n)){
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
		}
		set<int> s;
		map<int, int> left;//<节点，左孩子> 
		map<int, int> right; //<节点,右孩子> 
		int res;
		s.insert(a[0]);
		for(int i=1; i<n; i++){
			set<int>::iterator pos = s.lower_bound(a[i]);//直接后继 
			if(pos != s.end() && left.count(*pos)==0){//后继没有左孩子，插到后继的左孩子位置
				res = *pos;
				left[*pos] = a[i];
			}else{//后继有左孩子，或没有后继，插到前驱的右孩子位置 
				pos--;
				res = *pos;
				right[*pos] = a[i];
			}
			printf("%d ", res);
			s.insert(a[i]);
		}
		printf("\n");
	}
	return 0;
}
