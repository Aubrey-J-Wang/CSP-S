#include <iostream>
typedef long long ll;
using namespace std;

ll c[200010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//  freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	int n, w;
	cin >> n >> w;
	for(int i = 0; i < n; i++){
		int s, t, p;
		cin >> s >> t >> p;
		c[s] += p, c[t] -= p;
	}
	for(int i = 0; i < 200005; i++){
		c[i+1] += c[i];
		if(c[i] > w){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
