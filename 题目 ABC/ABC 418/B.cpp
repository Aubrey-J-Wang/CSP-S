#include <iostream>
#include <vector>
#include <iomanip>
#define double long double
using namespace std;

int sum[105];

int main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 't') sum[i]++;
		sum[i+1] = sum[i];
	}
	
	double maxn = 0;
	for(int l = 0; l < s.length()-1; l++){
		for(int r = l+2; r < s.length(); r++){
			if(r-l+1 >= 3){
				double x = sum[r]-sum[l-1]-2;
				double t = r-l-1;
				maxn = max(maxn, x/t);
			}
		}
	}
	cout << setprecision(15) << maxn;
	return 0;
}
