#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int N, M;
	cin >> N >> M;
	int A[N], B[M];

	for(int &i : A) cin >> i;
	for(int &i : B) cin >> i;

	long long ans = 0;

	sort(A, A+N);
	sort(B, B+M);

	int j = 0;
	for (int i = 0; i < M; i++) {
		while (B[i] > A[j] && j < N) j++;
		ans += A[j], A[j] = -1;
		if (j == N) {
			ans = -1;
			break;
		}
	}

	cout << ans;
	return 0;
}