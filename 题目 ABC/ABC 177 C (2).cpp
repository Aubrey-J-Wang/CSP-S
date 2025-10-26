#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 200005;
	long long ans = 0;
	cin >> n;
	long long a[n+1] = {0}, b[n+1] = {0};
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i+1] = b[i] + a[i];
	}
	for(int i = 0; i < n; i++){
		long long sum = (b[n]-b[i+1])%1000000007;
		ans += a[i]*sum;
		ans %= 1000000007;
	}
	cout << ans;
	return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<long long> B(N + 1, 0);
	int mod = 1000000007;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i + 1] = B[i] + A[i];
	}

	long ans = 0;

	for (int i = 0; i < N; i++)
	{
		long long sum = (B[N] - B[i + 1]) % mod;

		ans += A[i] * sum;
		ans %= mod;
	}

	cout << ans << endl;
}
*/