#include <iostream>
#include <cstring>
using namespace std;
int n1, n2, m, ans;
int result[101]; // 记录与 V2 中的点匹配的点的编号
bool state[101]; // 记录 V2 中的每个点是否被搜索过
namespace datum{
	bool data[101][101];
}
 // 邻接矩阵, "true"代表有边相连

bool find(int a) {
	using datum::data;
	for(int i = 1; i <= n2; i++) {
		if(data[a][i] == 1 && !state[i]) { //如果节点 i 与 a 相邻并且未被查找过
			state[i] = true; //标记 i 为已查找过
			
			if(result[i] == 0 || find(result[i])) { // 如果 i 未在前一个匹配 M 中, 或 i 在匹配 M 中，但是从与 i 相邻的节点出发可以有增广路
				result[i] = a; //记录查找成功记录
				return true; //成功
			}
		}
	}
	
	return false;
}

int main() {
	using datum::data;
	int t1, t2;
	memset(data, 0, sizeof(data));
	memset(result, 0, sizeof(result));
	cin >> n1 >> n2 >> m;
	
	for(int i = 1; i <= m; i++) {
		cin >> t1 >> t2;
		data[t1][t2] = true;
	}
	
	for(int i = 1; i <= n1; i++) {
		memset(state, 0, sizeof(state)); //清空
		if(find(i)) ans++;  //从节点 i 尝试扩展
	}
	
	cout << ans;
	return 0;
}
