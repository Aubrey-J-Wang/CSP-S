#include <iostream>
#include <vector>
#define int long long
using namespace std;
int read();
void write(int x);

void seperate(int n, vector<pair<int, int> >& a){
	a.clear();
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) a.push_back({i, 1}), n /= i;
		while(n%i == 0){
			a.back().second++;
			n /= i;
		}
	}
}

signed main(){
	int n = read(), m1 = read(), m2 = read();
	vector<pair<int, int> > divisors_m1;
	seperate(m1, divisors_m1);
	
	long long ans = 10000000;
	while(n--){
		int s = read(), maxn = 0, flag = 0;
		vector<pair<int, int> > divisors;
		seperate(s, divisors);
		if(divisors.size() != divisors_m1.size()) continue;
		for(int i = 0, j = 0; i < divisors.size(); i++){
			while(divisors_m1[i].first > divisors[j].first && j < divisors.size()) j++;
			if(divisors_m1[i].first < divisors[j].first){
				flag = 0;
//				cout << "#";
				break;
			}
			int add = 0;
			if((divisors_m1[i].second*m2) % divisors[j].second) add = 1;
			flag = 1, maxn = max(maxn, (divisors_m1[i].second*m2) / divisors[j].second + add);
		}
		if(!flag) continue;
		ans = min(ans, maxn);
	}
	if(ans == 10000000) write(-1);
	else write(ans);
	return 0;
}

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
