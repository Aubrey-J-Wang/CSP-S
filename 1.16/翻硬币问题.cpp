/*
 * 翻硬币  Coin Flipping (coin.cpp)
 *
 *  n 个正面朝上的硬币, 每次翻 5 个, 若能把这些硬币翻成反面全朝上,
 *
 *  打印使用最少步骤的每一步 (格式可运行此程序以确认), 否则输出 "No solution.".
 *
 **/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

queue< pair<int, int> > q;
bool vis[31];

int main() {
	ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);
//  注: 本题可用算术方法 O(n) 解出, 而这里展示的是 WFS.

	int n;
	cin >> n;

	q.push(make_pair(n, 0));
	vis[n] = true;

	while (!q.empty()) {
		int tmp = q.front().first;
		for (int i = 0; i <= min(5, tmp); ++i) {
			if (!vis[tmp - i + (5-i)]) {
				vis[tmp - i + (5-i)] = true;
				q.push(make_pair(tmp - i + (5-i), q.front().second + 1));
				if (tmp - i + (5-i) == 0) {
					cout << q.back().second;
					return 0;
				}
			}
		}

		q.pop();
	}

	cout << "No solution" << endl;
	return 0;
}
