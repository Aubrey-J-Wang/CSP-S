#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	vector<int> dp(1 << n, -1);
	
	dp[0] = 0;
	for(int i = 1; i < (1 << n); i++){
//	We list all the cases of the cards compressed using binary. So it can be understood that we are listing all the cases
//	that one will meet and trying hard to win. Then, we are able to get whether one can win in a particular case. Specially,
//	we list from the LAST CASE IN THE GAME to the first, so we can refer to a previous state with less cards when viewing a
//	case with more cards.
		bool f = false;
		for(int j = 0; j < n; j++)
			for(int k = j+1; k < n; k++){ // List all the card pairs that we can take.
				if(((i >> j) bitand 1) and ((i >> k) bitand 1)){ // Determine whether these cards are still on the table.
					if((a[j] == a[k] or b[j] == b[k]) and dp[i ^ (1 << j) ^ (1 << k)] == 0) f = true;
//					If we can take the cards, we detemine whether the new case is solvable, i.e. whether Takahashi can win.
				}
			}
		dp[i] = f; // Whether one can win in the current case.
	}
	
	cout << (dp.back() ? "Takahashi" : "Aoki"); // dp.back is an N-bit string all with 1.
	return 0;
}
