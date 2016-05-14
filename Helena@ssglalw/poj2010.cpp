#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_C = 100005;

int heap[MAX_C];

void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}

struct Heap
{
	int heap[MAX_C];//大顶堆
	int size;
	Heap(){size=0;}
	void insert(int x){
		size++;
		heap[size-1] = x;
		int i = size - 1;
		while(i > 0){
			int p = (i-1)/2;
			if(heap[p] < heap[i]){
				swap(heap[p], heap[i]);
				i = p;
			}else break;
		}
	}
	int getTop(){
		return heap[0];
	}
	void deleteTop(){
		heap[0] = heap[size-1];
		size--;
		int i = 0;
		while(i*2+1 < size){
			int lc = i*2+1, rc=i*2+2;
			int c = lc;
			if(rc<size && heap[rc]>heap[lc])
				c = rc;
			if(heap[c] > heap[i]){
				swap(heap[c], heap[i]);
				i = c;
			}else break;
		}
	}
};

struct Calf
{
	int score, aid;
}calves[MAX_C];
bool cmp(Calf c1, Calf c2){
	return c1.score < c2.score;
}

int N, C, F;
int before[MAX_C], after[MAX_C];

int main()
{
	freopen("2010.txt", "r", stdin);
	scanf("%d%d%d", &N, &C, &F);
	for(int i=0; i<C; i++){
		scanf("%d%d", &calves[i].score, &calves[i].aid);
	}
	int begin = N/2;
	int end = C-N/2-1;
	sort(calves, calves+C, cmp);

	if(N==1){
        printf("%d\n", calves[C-1].score);
        return 0;
	}

	Heap hb;

	//前begin的before[i]=0
	memset(before, 0, sizeof(before));
	memset(after, 0, sizeof(after));

	//printf("begin=%d\nend=%d\n", begin, end);
	for(int i=0; i<begin; i++){ //N为奇数,begin为中间数
		hb.insert(calves[i].aid);
		before[begin] += calves[i].aid;//前begin个必然算入before[begin]
	}
	//第begin个开始有对换
	for(int i=begin+1; i<=end; i++){
		if(calves[i-1].aid < hb.getTop()){//有比堆顶更小的aid,对换
			before[i] = before[i-1] - hb.getTop() + calves[i-1].aid;
			hb.deleteTop();
			hb.insert(calves[i-1].aid);
		}else before[i] = before[i-1];
	}

	Heap ha;
	for(int i=C-1; i>end; i--){
		ha.insert(calves[i].aid);
		after[end] += calves[i].aid;//后begin个必然算入after[C-begin]
	}
	//printf("after[%d] = %d\n", end, after[end]);
	int flag = -1;
    int sum = calves[end].aid + before[end] + after[end];
    if(sum <= F){
        printf("%d\n", calves[end].score);
        return 0;
    }
	for(int i=end-1; i>=begin; i--){ //开始从后往前枚举中位数i
        if(calves[i+1].aid < ha.getTop()){
			after[i] = after[i+1] - ha.getTop() + calves[i+1].aid;
			ha.deleteTop();
			ha.insert(calves[i+1].aid);
		}else after[i] = after[i+1];
		//printf("after %d: %d\n", i, after[i]);
		int sum = before[i] + after[i] + calves[i].aid;
		//printf("sum %d: %d\n", i, sum);
		if(sum <= F){
			flag = calves[i].score;
			break;
		}
	}
	printf("%d\n", flag);
	return 0;
}
