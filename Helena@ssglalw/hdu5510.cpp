#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N = 505;
const int MAX_L = 2005;

int T;
int n;
char str[MAX_N][MAX_L];
int len[MAX_N];
int next[MAX_N][MAX_L];

char has_cal[MAX_N];//是否已计算
char vis[MAX_N];//是否存在秩更大的母串

int Index_KMP(int s, int t, int pos, int next[]){
//下标从1开始，[0]无意义
	int i=pos, j=1;
	char* S = str[s];
	char* T = str[t];
	while(i<=len[s] && j<=len[t]){
		if(j==0 || S[i]==T[j]){i++; j++;}
		else j=next[j];
	}
	if(j>len[t]) return i-len[t];
	else return 0;
}

void get_next(int t, int* next){
	int i=1, j=0;
	char* T = str[t];
	int lt = len[t];
	next[0] = next[1] = 0;
	while(i<lt){
		if(j==0 || T[i]==T[j]){next[++i] = ++j;}
		else j=next[j];
	}
}

int main()
{
	freopen("5510.txt", "r", stdin);
	scanf("%d", &T);
	for(int ca = 1; ca<=T; ca++){
		
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%s", str[i]+1);
			len[i] = 0;
			for(int j=1; str[i][j]!='\0'; j++){
				len[i]++;//统计串长度
			}
		}
		
		memset(vis, 0, sizeof(vis));
		memset(has_cal, 0, sizeof(has_cal));
		int flag = 0;
		for(int i=1; i<n; i++){ 
			for(int j=0; j<i; j++){
				if(vis[j]) continue; //存在秩比它更大的母串，跳过此次比对
				if(!has_cal[j]) {
					get_next(j, next[j]);
					has_cal[j] = 1;
				}
				//printf("%s %s\n", str[i]+1, str[j]+1);
				if(Index_KMP(i, j, 0, next[j]) == 0){
					flag = i+1;
					break; //i是当前最优解
				}else vis[j] = 1;
			}
		}
		printf("Case #%d: %d\n", ca, flag ? flag : -1);
	}
	return 0;
}
