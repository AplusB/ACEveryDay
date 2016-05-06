#include <cstdio>
using namespace std;

int n;

int main(){
	freopen("1258.txt", "r", stdin);
	while(scanf("%d", &n)!=EOF){
		//printf("n: %d\n", n);
		int cnt = 0;
		getchar(); //吸收第一个n后的回车
		for(int i=0; i<n; i++){
			char s[10];
			gets(s);//gets()以当前字符开始，以回车结束
			//printf("%s\n", s);
			switch(s[0]){
				case 'S': cnt++; break;
				default: 
					if(s[2]=='1' && s[3]=='\0'){//WA在这里，注意多位数的情况，如12
						cnt++;
						break;
					}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}