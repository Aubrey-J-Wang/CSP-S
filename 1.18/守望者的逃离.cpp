#include <iostream>
using namespace std;
int d[14][300001], m, s, t;

int main() {
//	freopen(¡°escape.in¡±, ¡±r¡±, stdin);
//	freopen(¡°escape.out¡±, ¡±w¡±, stdout);

	cin >> m >> s >> t;
	int ti = 0, dist = 0;
	while (m >= 10) {
		m = m - 10;
		dist = dist + 60;
		if (dist >= s) {
			cout << "Yes" << endl << ti+1;
			return 0;
		}
		if ((++ti) == t) {
			cout << "No" << endl << dist;
			return 0;
		}
	}
	
	memset(d, 0, sizeof(d));
	int i, j;
	for (j = 0; j <= 13; j++) d[j][ti] = -(1 << 30);
	d[m][ti] = dist;
	
	for (i = ti; i < t; i++) {
		for (j = 0; j <= 13; j++) d[j][i + 1] = -(1 << 30);
		
		for (j = 0; j <= 13; j++) {
			if (d[j][i] >= s){
				cout << "Yes" << endl << i;
				return 0;
			}
			
			d[j][i + 1] = max(d[j][i] + 17, d[j][i + 1]);
			if(j >= 4) d[j][i + 1] = max(d[j - 4][i], d[j][i + 1]);
			else d[j][i + 1] = max(d[j + 10][i] + 60, d[j][i + 1]);
		}
	}
	
	int maxv = 0;
	for (j = 0; j <= 13; j++){
		if (d[j][t] >= maxv){
			maxv = d[j][t];
			if (maxv >= s){
				cout << "Yes" << endl << i;
				return 0;
			}
		}
	}
	cout << "No" << endl << maxv;
	return 0;
}