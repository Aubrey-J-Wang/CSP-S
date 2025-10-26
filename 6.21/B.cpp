#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;
	int D[N-1];
	for(int &i : D) cin >> i;
	for(int i = 0; i < N-1; i++){
		int sum = 0;
		for(int j = i; j < N-1; j++){
			sum += D[j];
			cout << sum << ' ';
		}
		cout << endl;
	}
	return 0;
}
