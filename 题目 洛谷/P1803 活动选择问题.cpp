#include<bits/stdc++.h>
using namespace std;
struct info{
	int begin_time, end_time;
} a[1000];
bool cmp(info a, info b){
	if(a.end_time != b.end_time) return a.end_time < b.end_time;
	else return a.begin_time > b.begin_time;
}
int n, cnt = 1, t;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i].begin_time >> a[i].end_time;
	sort(a, a+n, cmp);
	for(int i = 1; i < n; i++){
		if(a[t].end_time <= a[i].begin_time){
			t = i;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
/*
网站上似乎无这道题
下面补充信息:
有 n 个活动, 开始时间为 b[1...n], 结束时间为 e[1...n] 保证两者合理 (b[i] < e[i], i 为
1~n 间的数). 当
*/