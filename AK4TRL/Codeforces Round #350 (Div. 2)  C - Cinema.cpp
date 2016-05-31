//模拟贪心
//先统计各类语言人数
//进行音频和字幕筛选，若音频人数多则先选音频，若音频人数相等，比较字幕人数，选择最优
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
int a[200005], audio[200005], subtitles[200005];
map<int, int >M;
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
		scanf("%d",&a[i]), M[a[i]]++;

	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; ++i)
		scanf("%d",&audio[i]);

	for (int i = 0; i < m; ++i)
		scanf("%d",&subtitles[i]);

	int anum = 0, snum = 0, ans = 0;
	for (int i = 0; i < m; ++i){
		if (anum < M[audio[i]] || anum == M[audio[i]] && snum < M[subtitles[i]])
			anum = M[audio[i]], snum = M[subtitles[i]], ans = i;
	}

	printf("%d\n",ans+1);

	return 0;
}
