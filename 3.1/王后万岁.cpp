#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > city(32010);

int n, cnt;

void add_edge(int u, int v) {
	city[u].push_back(v);
}

int value[16010];
int sum[16010]; //sum[i]: Maximum value when considering subtree i.

void dfs(int u, int father) {
	sum[u] = value[u]; //At least we can get the value from the root of the tree.

	for (int i = 0; i < city[u].size(); i++) {
		if (city[u][i] == father) continue; //Do not go back to the father of the root of the subtree, or it will go wrong.

		dfs(city[u][i], u);

		sum[u] += max(0, sum[city[u][i]]); //If the maximum value of the subtree is less then 0, do not bother to conquer them.
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> value[i];

	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
		add_edge(b, a);
	}

	dfs(1, 0);

	int maxv = 0;
	for (int i = 1; i <= n; ++i)
		maxv = max(maxv, sum[i]); //Find the maximum value of all subtrees.

	cout << maxv << endl;
}


