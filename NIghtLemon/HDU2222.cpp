#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

const int MAXNODE = 250000;
const int SIGMA_SIZE = 26;

struct AutoMac{
	int next[MAXNODE][SIGMA_SIZE];
	int fail[MAXNODE];
	int end[MAXNODE];
	int root,L;
	
	int newnode(){
		for(int i=0;i<26;i++)
			next[L][i] = -1;
		end[L++] = 0;
		return L-1;
	}
	
	void init(){
		L = 0;
		root = newnode();
	}

	int idx(char c){
		return c-'a';
	}
	
	void insert(char *k){
		int len = strlen(k);
		int now = root;
		for(int i=0; i<len; i++){
			int c = idx(k[i]);
			if(next[now][c] == -1)
				next[now][c] = newnode();
			now = next[now][c];
		}
		end[now]++;
	}
	
	void build(){
		queue<int>Q;
		fail[root] = root;
		for(int i=0;i<26;i++){
			if(next[root][i] == -1)
				next[root][i] = root;
			else{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		}
		while(!Q.empty()){
			int now = Q.front();
			Q.pop();
			for(int i=0;i<26;i++){
				if(next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else{
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			} 
		}
	}
	
	int query(char *k){
		int len = strlen(k);
		int now = root;
		int ans = 0;
		for(int i=0; i<len; i++){
			int c = idx(k[i]);
			now = next[now][c];
			int tmp = now;
			while(tmp != root){
				ans += end[tmp];
				end[tmp] = 0;
				tmp = fail[tmp];
			}
		}
		return ans;
	}
	
	
}gao;

char k[1000007];

int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		gao.init();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",k);
			gao.insert(k);
		}
		gao.build();
		scanf("%s",k);
		printf("%d\n",gao.query(k));
	}
	return 0;
}
