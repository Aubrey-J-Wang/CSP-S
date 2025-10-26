#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int read();
void write(int x);

struct score{
	int chinese, maths, english;
	int id, place;
};

bool cmp(score a, score b){
	if(a.english + a.chinese + a.maths != b.english + b.maths + b.chinese) return a.english + a.chinese + a.maths > b.english + b.maths + b.chinese;
	else if(a.chinese + a.maths != b.chinese + b.maths) return a.chinese + a.maths > b.chinese + b.maths;
	else if(max(a.chinese, a.maths) != max(b.chinese, b.maths)) return max(a.chinese, a.maths) > max(b.chinese, b.maths);
	else return false;
}

bool cmp2(score a, score b){
	return a.id < b.id;
}

int main(){
	int n = read();
	score a[n];
	int j = 0;
	for(auto& [c, m, e, p, x] : a) cin >> c >> m >> e, p = ++j;
	sort(a, a+n, cmp);
	
	for(int i = 0; i < n; i++){
		if(i == 0){
			a[i].place = i+1;
			continue;
		}
		auto A = a[i], b = a[i-1];
		if(A.english + A.chinese + A.maths == b.english + b.maths + b.chinese and
		   A.chinese + A.maths == b.chinese + b.maths
		   and max(A.chinese, A.maths) == max(b.chinese, b.maths)) a[i].place = a[i-1].place;
		else a[i].place = i+1;
	}
	
	sort(a, a+n, cmp2);
	for(auto i : a) cout << i.place << endl;
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

