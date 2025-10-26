#include <iostream>
#include <vector>
using namespace std;

int main(){
	string P;
	int L;
	cin >> P >> L;
	if(P.length() >= L) cout << "Yes";
	else cout << "No";
	return 0;
}
