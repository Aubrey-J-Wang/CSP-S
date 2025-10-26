#include <cstring>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f, MAXN = 10, N = 5, M = 6;

int a[MAXN][MAXN], tmp[MAXN][MAXN], ans[MAXN][MAXN];

void turn(int i, int j) {
	tmp[i][j] ^= 1;
	tmp[i - 1][j] ^= 1;
	tmp[i + 1][j] ^= 1;
	tmp[i][j - 1] ^= 1;
	tmp[i][j + 1] ^= 1;
}

int main() {
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) cin >> a[i][j];
	}

	for(int i = 0; i < (1 << M); i++) {
		memcpy(tmp, a, sizeof a);
		memset(ans, 0, sizeof ans);
		for(int j = 1; j <= M; j++) {
			if((i >> (j - 1)) & 1) turn(1, j), ans[1][j] = 1;
		}
		
		for(int j = 2; j <= N; j++)
			for(int k = 1; k <= M; k++) {
				if(tmp[j - 1][k] == 1) turn(j, k), ans[j][k] = 1;
			}

		bool flag = true; // Viewing while doing or only view the last row.
		for(int j = 1; j <= N and f; j++)
			for(int k = 1; k <= M; k++) {
				if(tmp[j][k]) {
					f = false;
					break;
				}
			}
		if(flag){
			for(int j = 1; j <= N; j++) {
				for(int k = 1; k <= M; k++) cout << ans[j][k] << ' ';
				cout << endl;
			}
		}
	}
	
	return 0;
}