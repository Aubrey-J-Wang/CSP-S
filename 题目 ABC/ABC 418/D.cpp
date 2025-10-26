#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num[2][200005], a[200005];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) a[i] = getchar()-'0';
	
	for(int i = 0; i < n; i++){
		num[a[i]][i]++;
		num[0][i+1] = num[0][i];
		num[1][i+1] = num[1][i];
	}
	
	int ans = num[1][n-1];
	queue<int> q;
	int num_0 = 0, num_1 = 0, pop_0 = 0, pop_1 = 0;
	for(int i = 0; i < n; i++){
		q.push(a[i]);
		if(a[i]) num_1++;
		else num_0++;
		
		if(num_1%2 == 0 && num_1%2 == 0) ans++;
		else{
			if(q.back() == a[i]) q.pop();
			if(a[i]) num_1--, pop_1++;
			else num_0--, pop_0++;
			ans += max(pop_0/2, pop_1/2) + 1;
		}
	}
	cout << ans;
	return 0;
}
