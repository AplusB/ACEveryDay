#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")

char cur[20];
int state;
bool flag;//以回车还是空格结束这句话
bool start;

bool lower(char c){
    if(c >= 'a' && c <= 'z') return true;
    return false;
}
bool upper(char c){
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}

bool stateChange(char* arr){
	switch(state){
		case 0:
			state = 1;//读入了首单词
			break;
		case 1:
			if(arr[0] == '.'){
				//printf("a period\n");
				state = 0; //此句结束，期待新句开始
			}
			else ;//非首单词，逗号
			break;
	}
	return true;
}

void performAction(char* arr){
	switch(state){
		case 0:
			//printf("new sentence\n");
			if(start == 0)
				start = 1;
			else {
				if(flag) pn();
				else printf(" ");
				flag = 0;
			}
			arr[0] = toupper(arr[0]);//首单词的首字母大写
			printf("%s", cur);//首单词，第二句开始的，所以要和前面的句号有一个换行
			break;
		case 1:
			if(arr[0] == '.'){//句号后是回车还是空格，得读到下一个首单词才能知道
				printf("%s", arr);
			}else if(arr[0] == ',')
				printf("%s", arr);
			else printf(" %s", arr);//非首单词
			break;
	}
}

int main()
{
	FREAD("hiho107.txt");
	state = 0;
	start = 0;//全局的第一句
	char c;
	while((c = getchar()) != EOF){//空格不会被读入
		if(c == ' ' || c == '\n'){
			if(c == '\n') flag = 1;
			continue;
		}
		int i = 0;
		for(; c != ' ' && c != '\n' && c != EOF; i++){//大写全部转换为小写
			cur[i] = c;
			if(upper(cur[i]))
				cur[i] = tolower(cur[i]);
			c = getchar();
		}
		cur[i] = '\0';
		//PSTR(cur);
		if(c == '\n') flag =1;//向前看一个字符
		if(i > 1 && (cur[i-1] == ',' || cur[i-1] == '.')){//标点粘连在单词末尾
			char pun[2];
			pun[0] = cur[i-1]; pun[1] = '\0';//封装为字符串
			cur[i-1] = '\0';//原单词抹除末尾标点

			performAction(cur);
			stateChange(cur);

			performAction(pun);
			stateChange(pun);
		}else{
			performAction(cur);
			stateChange(cur);
		}
	}
	pn();
	return 0;
}
