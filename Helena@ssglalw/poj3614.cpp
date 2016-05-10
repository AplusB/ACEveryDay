#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_C = 2505;
const int MAX_L = 2505;
int C, L;
struct Cow
{
	int min, max;
	Cow& operator = (Cow& c){
		min = c.min;
		max = c.max;
		return *this;
	}
}cows[MAX_C];

struct Lotion
{
	int spf,cover;
}lotions[MAX_C];

bool cmpL(Lotion l1, Lotion l2){
	return l1.spf < l2.spf;
}
bool cmpC(Cow c1, Cow c2){
	return c1.min < c2.min;
}

int heap[MAX_C]; //小顶堆
int size = 0;

void insert(int x){
	size++;
	heap[size-1] = x;//目标元素暂时插到末尾
	int i = size - 1;//候选目标位置
	while(i > 0){//上滤，反复与父节点比较
		int p = (i-1)/2;//比较候选位置的父节点和目标元素
		if(heap[p] > x){
			heap[i] = heap[p];//父节点下沉
			i = p;//候选位置上升
		}else break;
	}
	heap[i] = x;
}

void deleteTop(){
	heap[0] = heap[size-1];
	size--;
	int x = heap[0]; //把末尾元素提到堆顶
	int i = 0; //候选目标位置
	while(i*2+1 < size){//下滤
		int lc = i*2+1;
		int rc = i*2+2;
		int c = lc;
		if(rc<size && heap[rc]<heap[lc])
			c = rc;
		if(heap[c] < x){
			heap[i] = heap[c];
			i = c;
		}else break;
	}
	heap[i] = x;
}

int getTop(){
	return heap[0];
}

int main()
{
	freopen("3614.txt", "r", stdin);
	scanf("%d%d", &C, &L);
	for(int i=0; i<C; i++){
		scanf("%d%d", &cows[i].min, &cows[i].max);
	}

	for(int i=0; i<L; i++){
		scanf("%d%d", &lotions[i].spf, &lotions[i].cover);
	}
	
	sort(lotions, lotions+L, cmpL);
	sort(cows, cows+C, cmpC);
	
	
	for(int i=0; i<C; i++){
		//printf("cow %d %d\n", cows[i].min, cows[i].max);
	}

	int cnt = 0;
	for(int i=0, j=0; i<L; i++){
		//printf("lotion %d %d\n", lotions[i].spf, lotions[i].cover);
		while(j<C && cows[j].min <= lotions[i].spf){
			insert(cows[j].max);
			j++;
			//printf("insert %d\n", cows[j-1].max);
		}
		int vol = lotions[i].cover;
		
		while(vol > 0 && size>0){
			if(getTop() >= lotions[i].spf){
				vol--;
				cnt++;
				//printf("add %d\n", getTop());
			}
			deleteTop();
			//printf("%d\n", cnt);
		}
	}
	printf("%d\n", cnt);
	return 0;
}
