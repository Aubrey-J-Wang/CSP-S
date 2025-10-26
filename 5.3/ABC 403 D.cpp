#include <iostream>
#include <vector>
using namespace std;

int M = 100001;

int calc(int x){
/*
	if not x:
        return 0
    x = [0] + x
    dp = [0] * (len(x) + 1)
    for i in range(1, len(x)):
        dp[i + 1] = min(dp[i] + x[i], dp[i - 1] + x[i - 1])
    return dp[-1]
?*/
}

int main(){
	int n, d;
	cin >> n >> d;
	int a[n];
	for(int &i : a) cin >> i;
	
	int cnt[M] = {0};
	for(int i : a) cnt[i]++; // Number of number i in a.
	
	if(d == 0){
		int sum = 0;
		for(int i : cnt) sum += max(i-1, 0); // If D = 0, we delete all same elements.
		cout << sum;
		return 0;
	}
	
	int ans = 0;
	for(int i = 0; i < d; i++){
//		ans += calc(cnt[i::D]); ???
	}
	
	cout << ans;
	return 0;
}
