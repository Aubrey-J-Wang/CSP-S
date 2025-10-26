/*
 * ��Ӳ��  Coin Flipping (coin.cpp)
 *
 *  n �����泯�ϵ�Ӳ��, ÿ�η� 5 ��, ���ܰ���ЩӲ�ҷ��ɷ���ȫ����,
 *
 *  ��ӡʹ�����ٲ����ÿһ�� (��ʽ�����д˳�����ȷ��), ������� "No solution.".
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
//  ע: ��������������� O(n) ���, ������չʾ���� WFS.

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
