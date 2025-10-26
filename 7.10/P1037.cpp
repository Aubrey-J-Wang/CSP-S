#include <iostream>
using namespace std;

bool tag[10][10];
int d[10], p[505] = {1};

int main() {
	string a;
	int n;
	cin >> a >> n;
	while(n--) {
		int x, y;
		cin >> x >> y;
		tag[x][y] = true;
	}

	for(int k = 1; k <= 9; k++)
		for(int i = 0; i <= 9; i++)
			for(int j = 1; j <= 9; j++){
				if(tag[i][k] and tag[k][j]) tag[i][j] = true;
			}	

	for(int i = 0; i <= 9; i++) {
		tag[i][i] = true;
		for(bool j : tag[i]) d[i] += j;
	}

	for(auto j : a) {
		int x = d[j - '0'], z = 0;
		for(int i = 0; i < 500; i++) p[i] = p[i] * x + z, z = p[i] / 10, p[i] %= 10;
	}
	int i = 500;
	while(p[i] == 0) i--;

	for(; i >= 0; i--) cout << p[i];
	return 0;
}