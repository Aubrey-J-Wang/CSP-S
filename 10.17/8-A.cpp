#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define int long long
#define loop(i, n, m) for(int i = (n); (i) < (m); i++)
#define rev_loop(i, n, m) for(int i = (n); (i) >= (m); i--)
using namespace std;

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

signed main(){
	int n = read();
	deque<pair<int, int> > dq;
	int sum = 0;
	while(n--){
		int opt = read(), price = read(), Time = read();
		dq.shrink_to_fit();
		if(!dq.empty()) while(dq.back().first < Time-45 and !dq.empty()) dq.pop_back();
		if(opt == 0) dq.push_front({Time, price}), sum += price;
		else{
			bool flag = false;
			dq.shrink_to_fit();
			if(!dq.empty()) for(int i = dq.size()-1; i >= 0; i--){
				if(dq[i].second >= price){
					dq.erase(dq.begin()+i);
					flag = true;
					break;
				}
			}
			if(!flag) sum += price;
		}
		dq.shrink_to_fit();
	}
	write(sum);
	return 0;
}
