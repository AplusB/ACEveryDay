#include <cstdio>
#include <vector>
using namespace std;

class ZigZag
{
public:
	ZigZag(){}
	~ZigZag(){}
	int longestZigZag(vector<int> sequence){
		if(sequence.size() == 1) return 1;

		vector<int> dif(sequence.size());
		for(int i=1; i<sequence.size(); i++)
			dif[i] = sequence[i] - sequence[i-1];
		int s = 1;//第一个不重的
		while(s < sequence.size() && sequence[s] - sequence[s-1]==0) s++;
		if(s == sequence.size()) return 1;//只有一个值
		int t = dif[s]>0 ? 1 : -1;//第一个差值
		int ans = 2;
		for(int i=s; i<dif.size(); i++){
			if(dif[i] * t < 0){
				//printf("%d\n", dif[i]);
				t = -t;
				ans++;
			}
		}
		return ans;
	}	
};

int a[] = {70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32};

int main()
{
	ZigZag t;
	printf("%d\n", t.longestZigZag(vector<int>(a, a+sizeof(a)/sizeof(int))));
	return 0;
}
