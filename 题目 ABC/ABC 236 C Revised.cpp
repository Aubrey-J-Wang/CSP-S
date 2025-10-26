#include <iostream>
using namespace std;
int n, m;
string s[100010], t[100010];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= m; i++) cin >> t[i];

	int i = 1, j = 1;

	while(i <= n){
		if(s[i] == t[j]){
			cout << "Yes" << endl;
			j++;
		}else cout << "No" << endl;
		i++;
	}
	return 0;
}