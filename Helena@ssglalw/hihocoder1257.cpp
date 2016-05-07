#include <cstdio>
using namespace std;
int n;
int H, W;

void printOdd(int x, int y){
	printf("%d %d ", x, y);
}

void printEven(int x, int y){
	printf("%d %d ", x, y+H);
}

int main(){
	while(~scanf("%d", &n)){
		H = (n+1)/2;
		W = n&1 ? n : n+1;
		printf("%d %d\n", H, W);
		for(int i=1; i<=n; i++){
			if(i&1){
				int x = H, y = H - i/2;
				while(x > y){
					printOdd(x, y);
					x--;
				}
				printOdd(x, y);
				y++;
				while(y <= H){
					printOdd(x, y);
					y++;
				}
			}else{
				if(n%4==0 || (n+1)%4==0){
					int len = i/2;
					if(i%4 == 0){
						int x = H, y = i/2;
						while(x > H - len + 1){
							printEven(x, y);
							x--;
						}
						printEven(x, y);
						y++;
						while(x <= H){
							printEven(x, y);
							x++;
						}
					}else {
						int x = H - i/2 + 1, y = 1;
						while(y < len){
							printEven(x, y);
							y++;
						}
						printEven(x, y);
						x--;
						while(y >= 1){
							printEven(x, y);
							y--;
						}
					}	
				}else{
					int len = i/2;
					if(i%4 == 0){
						int x = H - i/2 + 1, y = 1;
						while(y < len){
							printEven(x, y);
							y++;
						}
						printEven(x, y);
						x--;
						while(y >= 1){
							printEven(x, y);
							y--;
						}
					}else{
						int x = H, y = i/2;
						while(x > H - len + 1){
							printEven(x, y);
							x--;
						}
						printEven(x, y);
						y++;
						while(x <= H){
							printEven(x, y);
							x++;
						}
					}
				}	
			}
		printf("\n");	
		}
	}
	return 0;
}