/*
三星塔(tower.cpp / c / pas)
【问题描述】
最近考古学家有一个有趣的发现：许多遗迹中，塔往往是三个三个出现的。在许多古迹
中的文字表明，这种塔被称为 “三星塔” 。它们常常排在正三角形的三个顶点上——不过不总
是。唯一一定的是，三个塔高度总是相等的。
因此，考古学家们很想用手上现有的东西来复原一个三星塔。然而由于经费限制，他们
手上仅有为数不多的几块砖块，而且无法将它们弄碎。不过，他们仍然很想知道，能不能把
它们搭成三座高度一样的塔呢？注意每块砖块都得用上。
【输入】
第一行一个数 T（T <= 10），测试数据组数。
对于每组测试数据：
第一行一个正整数 N（N <= 20），砖块数目。
接下来一行 N 个正整数用空格分隔，每块砖高度 ( <= 30)。
【输出】
T 行，对于每组数据，如果可以办到输出 "YES" 否则输出 "NO" (不含引号)
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#define maxlongint 2147483647
//const int MAXINT = 2147483647;
using namespace std;
int tt, n, ss, a[200], f[100][200][200]; //100、 200、 200？

//int tt, n, ss;
//int a[200],f[100][200][200];
int main() {
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	cin >> tt;
	for (int gb = 1; gb <= tt; gb++) {
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		cin >> n;
		ss = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ss += a[i]; // 所有砖块高度的和
		}
		if (ss % 3 != 0)
			cout << "NO" << endl;
		else {
			ss /= 3; // 分成三份后，一份的量
			f[0][0][0] = 1;
			for (int i = 0; i < n; i++) //可否倒推？可省掉第一维？
				for (int j = 0; j <= ss; j++)
					for (int k = 0; k <= ss; k++)
						if (f[i][j][k] == 1) {
							if (j + a[i + 1] <= ss)
								f[i + 1][j + a[i + 1]][k] = 1;
							if (k + a[i + 1] <= ss)
								f[i + 1][j][k + a[i + 1]] = 1;
							f[i + 1][j][k] = 1;
						} // 第三堆的高度值为何不计算?
			int flag = 1;
			for (int i = 1; i <= n; i++) //不用扫描，只看 f[n][ss][ss]
				if (f[i][ss][ss] == 1)
					flag = 0;
// 要否看 f[n][ss][ss]==1? 要否加 break?
			if (flag == 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}