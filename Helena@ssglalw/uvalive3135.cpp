#include <cstdio>
#include <queue>
using namespace std;
const int MAX_N = 1005;

char comm[20];
int k;

struct Query
{
	int id;
	int period;
	int time;
	bool operator < (const Query& a) const{
		return time > a.time || (time == a.time && id > a.id);
	}
}q;

priority_queue<Query> pq;

int main()
{
	freopen("in", "r", stdin);
	while(~scanf("%s", comm)){
		if(comm[0] == '#') break;
		scanf("%d%d", &q.id, &q.period);
		q.time = q.period;
		pq.push(q);
	}
	scanf("%d", &k);
	while(k--){
		q = pq.top();
		pq.pop();
		printf("%d\n", q.id);
		q.time += q.period;
		pq.push(q);
	}
	return 0;
}
