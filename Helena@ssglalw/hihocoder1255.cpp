#include <cstdio>
#include <algorithm>
using namespace std;

struct Rec{
	int w, h;
	Rec& operator = (Rec& r){
		w = r.w;
		h = r.h;
		return *this;
	}
}rec[4];

int n;
int index[4];

void swap(Rec& r){ //注意传引用，否则只交换了形参。。。 
	int temp = r.w;
	r.w = r.h;
	r.h = temp;
}

void reverse(int x){
	for(int i=0; i<3; i++){
		if(x&1){
			swap(rec[index[i]]);
		}
		x >>= 1;
	}
}


bool judge(){	
	int ans = false;
	
	if(rec[index[0]].w == rec[index[1]].w 
		&& rec[index[1]].w == rec[index[2]].w )
		ans = true;
	else if(rec[index[1]].w == rec[index[2]].w 
		&& rec[index[0]].h == rec[index[1]].h + rec[index[2]].h) 
		ans = true;
		
	return ans;
}

int main()
{
	scanf("%d", &n);
	while(n--){
		for(int i=0; i<4; i++){
			scanf("%d%d", &rec[i].w, &rec[i].h);
			index[i] = i;
		}
		int flag = 0;
		do{
			for(int i=0; i<8; i++){
				reverse(i);
				if(judge()){
					flag = 1;
					break;
				}
				reverse(i);	
			}
			if(flag) break;
		}while(next_permutation(index, index+4));
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}
