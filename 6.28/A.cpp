#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, ans = 0;
	cin >> n;
	while(n--){
		int a, b;
		cin >> a >> b;
		ans += (b > a);
	}
	cout << ans;
	return 0;
}
