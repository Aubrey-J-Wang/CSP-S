#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int N, L;
    cin >> N >> L;
    if(L%3){
    	cout << 0;
    	return 0;
	}
	
	int d[N-1];
	for(int &i : d) cin >> i;
	
	int cnt[L] = {0}, x = 0;
	for(int i = 0; i < N; i++){
		if(i) x += d[i-1];
		x %= L;
		cnt[x]++
	}
	
	int ans = 0;
	for(int i = 0; i <= L/3; i++){
		ans += cnt[i] * cnt[i+L/3] * cnt[i+2*L/3];
	}
	cout << ans;
	return 0;
}
