#include <iostream>
#include <vector>
#include <algorithm>
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

bool comp(pair<int, string> a, pair<int, string> b){
	if(a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

int main(){
	int n = read(), k = read();
	string s;
	cin >> s;
	vector<pair<int, string> > num;
	for(int i = 0; i <= s.length()-k; i++){
		string t = s.substr(i, k);
		int flag = false;
		for(auto& [v, u] : num){
			if(u == t){
				v++, flag = true;
				break;
			}
		}
		if(!flag) num.push_back({1, t});
	}
	sort(num.begin(), num.end(), comp);
	write(num[0].first), putchar('\n');
	int j = 0;

	while(num[j].first == num[0].first) cout << num[j++].second << ' ';
	return 0;
}
