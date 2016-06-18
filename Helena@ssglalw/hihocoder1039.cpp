#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define FREAD(FN) freopen((FN), "r", stdin)
#define pb(a) push_back(a)
#define SINT(X) scanf("%d", &(X))
using namespace std;
const int MAX_C = 105;

struct Node
{
	char c;
	int next;
}nodes[MAX_C];//静态链表
int n;//节点个数
int head;

int T;
char s[MAX_C];
int ans;

void reset(){//重置为原始序列
	n = 0;
	for(int i = 0; s[i] != '\0'; i++){//[1, n]
		nodes[i].next = i+1;//来自前驱的引用
		nodes[i+1].c = s[i];//[0]为头结点
		n++;
	}
	nodes[n].next = -1;//末元的后继
}

int main()
{
	FREAD("1039.txt");
	head = 0;
	SINT(T);
	while(T--){
		scanf("%s", s);
		ans = 0;
		reset();//初始化原始序列
		for(char t = 'A'; t <= 'C'; t++){
			nodes[n+1].c = t;//待插入的元素统一放在[n+1]
			for(int i=0; i<=n; i++){//插在i与i+1之间
				// if(nodes[i].c != t && nodes[i+1].c != t) continue;//这里不能剪枝！！BBBAB这个可以在第一个B后插入一个A而全部消掉
				//printf("insert %c after index %d\n", t, i);
				nodes[n+1].next = nodes[i].next;
				nodes[i].next = n + 1;
				int cnt = 0;
				bool updated = 1;//这趟扫描是否发生了消除
				head = 0;
				// printf("before disappear\n");
				// for(int j = nodes[head].next; j != -1; j = nodes[j].next){
				// 	printf("%c", nodes[j].c);
				// }
				// printf("\n");
				while(updated){//这趟扫描没有发生消除，则退出
					updated = 0;
					int discovered = 0;
					int pre = head;//cur的前驱
					int cur = nodes[head].next;
					while(cur != -1 && nodes[cur].next != -1){//一趟自左到右的扫描
						int j = nodes[cur].next;
						//printf("%c %c\n", nodes[cur].c, nodes[j].c);
						while(j != -1 && nodes[j].c == nodes[cur].c){
							updated = 1;//发现可消
							discovered = 1;//发现了以cur为开始可消串
							cnt++;
							//printf("delete %c\n", nodes[j].c);
							nodes[cur].next = nodes[j].next;//删除j
							j = nodes[j].next;
						}
						if(discovered){//发现连续的cur,可消
							cnt++;//加上开头的cur
							discovered = 0;
							nodes[pre].next = nodes[cur].next;//删除cur
							cur = nodes[pre].next;//新的起点
						}else{//未发现,cur只有一个
							pre = cur;
							cur = nodes[cur].next;
						}
						// printf("delete one cluster\n");
						// for(int j = nodes[head].next; j != -1; j = nodes[j].next){
						// 	printf("%c", nodes[j].c);
						// }
						// printf("\n");
					}
					// printf("disappear once\n");
					// for(int j = nodes[head].next; j != -1; j = nodes[j].next){
					// 	printf("%c", nodes[j].c);
					// }
					// printf("\n");
				}
				nodes[i].next = nodes[n+1].next;//删除插入的[n+1]
				ans = max(ans, cnt);
				//printf("ans this %d\n", cnt);
				reset();
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
