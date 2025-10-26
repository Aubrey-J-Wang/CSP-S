#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void answer(bool out, int v) {
	if(out) cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << v;
	return;
}
int d[14][300001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, s, t;
//	freopen(“escape.in”, ”r”, stdin);
//	freopen(“escape.out”, ”w”, stdout);
	cin >> m >> s >> t;
	int ti = 0, dist = 0; //ti: 已用的时间; dist: 已走过的距离
//  先尽量使用魔法值
	while (m >= 10) {
		m = m - 10;
		dist = dist + 60;
		if (dist >= s) { //只用魔法值就可以逃离，则输出已用的时间
			answer(true, ti + 1);
			return 0;
		}
		if ((++ti) == t) {
// 		魔法值还未用完即已达时间上限，则输出逃离的最大距离
			answer(false, dist);
			return 0;
		}
	}
	memset(d, 0, sizeof(d));
	int i, j;
// 	初始化 d[j][ti]为一个负数
	for (j = 0; j <= 13; j++) d[j][ti] = -(1 << 30);
	d[m][ti] = dist;
	for (i = ti; i < t; i++) {
//		按时间划分阶段, 上限是岛沉没的时间
		for (j = 0; j <= 13; j++)
			d[j][i + 1] = -(1 << 30);
		for (j = 0; j <= 13; j++) {
			if (d[j][i] >= s) { //走过的距离大于与出口的距离， 则输出当前已用时间
				answer(true, i);
				return 0;
			}
// 状态转移方程
			d[j][i + 1] = max(d[j][i] + 17, d[j][i + 1]);
			if (j >= 4) d[j][i + 1] = max(d[j - 4][i], d[j][i + 1]);
			if (j < 4) d[j][i + 1] = max(d[j + 10][i] + 60, d[j][i + 1]);
		}
	}
// 找到最后时刻所有状态中之距离最大者
	int maxv = 0;
	for (j = 0; j <= 13; j++)
		if (d[j][t] >= maxv) {
			maxv = d[j][t];
			if (maxv >= s) {
				answer(true, i);
				return 0;
			}
		}
	answer(false, maxv); // 否则，无法逃离，输出能够达到的最大距离
	return 0;
}
/*
//贪心
#include <iostream>
using namespace std;
int m, s, t, min, max, k, temp, m1, t1, i;
bool flag;

int main() {
	ios::sync_with_stdio(false);
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	cin >> m >> s >> t;
	max = 0; //不能逃离荒岛时的最远距离
	min = 0x3f3f3f3f; //能逃离的最短时间
	flag = false; //是否能够逃离的标记
	for (int i = t; i >= 0; i--) { //枚举恢复魔法的时间，可以为 0
		m1 = m + 4 * i; //总魔法值
		t1 = m1 / 10; //可以使用闪烁的次数，由于 1s 一次闪烁， t1 也等于闪烁所用时间
		if (t1 > t)
			t1 = t; //如果说闪烁用时超过总时间，那么没有用处。于是将闪烁时间赋为总时间
		if (t - t1 - i < 0)
			continue; //如果说闪烁时间与恢复魔法的时间大于总时间，那么不成立
		temp = t1 * 60 + (t - t1 - i) * 17; //(用完所有时间的) 总路程=闪烁+跑步
		if(temp > s){ //如果可以逃出岛
		//本着尽量使用闪烁的原则，减少跑步时间，使得实际时间尽量少。
			flag = true;
			k = t - t1 - i;
			while(k > 0 and temp - 17 > s) k--, temp -= 17;
			if(k + i + t1 < min) min = k + i + t1; //最小时间
			if(temp > max) max = temp; //最长距离
			if(flag){
				cout << "Yes" << endl;
				cout << min;
			}else{
				cout << "No" << endl;
				cout << max;
			}
		}
	}
	return 0;
}
*/