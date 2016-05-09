#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 10005;

int heap[MAX_N];//大顶堆 
int size;

void push(int x){
	size++;
	heap[size-1] = x;
	int i = size-1;
	while(i>0){
		int p = (i-1)>>1;
		if(heap[p] >= x) break;
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}

int pop(){
	int top = heap[0];
	heap[0] = heap[size-1];
	size--;
	int x = heap[0];
	int i = 0;
	while(i*2+1 < size){
		int lc = i*2+1;
		int rc = i*2+2;
		int c = lc;
		if(rc<size && heap[rc]>heap[lc])
			c = rc;
		if(heap[c] <= x) break;
		heap[i] = heap[c];
		i = c;
	}
	heap[i] = x;
	return top;
}

struct Stop
{
	int dis, vol;
}stops[MAX_N];

bool cmp(Stop s1, Stop s2){
	return s1.dis < s2.dis;
}

int n;
int L, P;

int main()
{
	freopen("2431.txt", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d%d", &stops[i].dis, &stops[i].vol);
	}
	scanf("%d%d", &L, &P);
	stops[0].dis = 0;//终点town
	stops[n+1].dis = L;//起点看作第一个加油站 
	stops[n+1].vol = P;

	sort(stops, stops+n+1, cmp);//按距离排序 

	for(int i=n+1; i>=1; i--)//改成存到下一个加油站的距离 
	{
		stops[i].dis -= stops[i-1].dis;
	}
	
//	for(int i=0; i<=n+1; i++){
//		printf("%d %d\n", stops[i].dis, stops[i].vol);
//	}

	int cur_vol = 0;
	int cnt = -1;
	for(int i=n+1; i>=1; i--){
		push(stops[i].vol);
		cur_vol -= stops[i].dis;
		if(cur_vol < 0){
			int flag = 0;
			while(size>0){
				cur_vol += heap[0];
				pop();
				cnt++;
				if(cur_vol >= 0){
					flag = 1;
					break;
				}
			}
			if(!flag){
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
