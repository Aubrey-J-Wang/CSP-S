#include <iostream>
#include <vector>
using namespace std;

const int MAXN = INT_MAX, MINN = INT_MIN;

int dp_min[210][210], dp_max[210][210], sum[210];
int main() {
	int N;
	cin >> N;
	vector<int> a(2 * N);
	for(int i = 1; i <= N; ++i) cin >> a[i], a[i + N] = a[i];
	
	for(int i = 1; i <= 2 * N; ++i) sum[i] = sum[i - 1] + a[i], dp_min[i][i] = 0, dp_max[i][i] = 0;
	
	for(int L = 2; L <= N; ++L) {
		for(int i = 1; i <= 2 * N - L + 1; ++i) {
			int j = i + L - 1;
			dp_min[i][j] = MAXN, dp_max[i][j] = MINN;
			
			for(int k = i; k < j; ++k) {
				dp_min[i][j] = min(dp_min[i][k] + dp_min[k + 1][j], dp_min[i][j]);
				dp_max[i][j] = max(dp_max[i][k] + dp_max[k + 1][j], dp_max[i][j]);
			}
			
			dp_min[i][j] += (sum[j] - sum[i - 1]);
			dp_max[i][j] += (sum[j] - sum[i - 1]);
		}
	}
	
	int ans_min = MAXN, ans_max = MINN;
	
	for(int i = 1; i <= N; ++i) {
		ans_min = min(ans_min, dp_min[i][i + N - 1]);
		ans_max = max(ans_max, dp_max[i][i + N - 1]);
	}
	
	cout << ans_min << endl << ans_max;
	return 0;
}
