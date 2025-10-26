#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    string i;
    cin >> i;
    cout << "+(";
    for(int j = 0; j < i.length(); j++){
    	int num = i[j]-'0';
    	cout << "+(";
    	for(int k = 1; k <= num; k++){
    		cout << "+!+[]";
		}
		cout << "+[]";
		cout << ")";
	}
	cout << ")";
	return 0;
}
