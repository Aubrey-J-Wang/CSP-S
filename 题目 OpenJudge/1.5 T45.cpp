#include <iostream>
using namespace std;
int main (){
	int n;
    cin >> n;
    int sum = 0, s = 0;
    for(int i = 1; s < n; i++){
        for(int j = 1; j <= i && j+s <= n; j++){
            sum += i;
        }
        s += i;
    }
    cout << sum;
	return 0;
}

