#include <iostream>
#include <utility>
using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b)
}

void simplify(pair<int, int>& frac){
	frac.first /= gcd(abs(frac.first), abs(frac.second));
	frac.second /= gcd(abs(frac.first), abs(frac.second));
}

bool prime(int x){
	for(int i = 2; i*i <= x; i++){
		if(x%i == 0) return false;
	}
	return true;
}

auto qe1u(int a, int b, int c){
	pair<int, int> Q, R;
	Q = {-b, 2*a};
	simplify(Q);
	R = {b*b-4*a*c, 2*a};
	if(sqrt(R.first) == floor(sqrt(R.first))){
		R.first = sqrt(R.first);
		simplify(R);
		Q = {Q.first*R.second+Q.second*R.first, Q.second*R.second};
		simplify(Q);
		return pair<pair<int, int>, pair<int, int> >(Q, {0, 1});
	}
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		int discriminant = b*b-4*a*c;
		if(discriminant < 0){
			cout << "NO";
			continue;
		}
		if(a < 0) a = -a, b = -b, c = -c;
		print(qe1u(a, b, c));
		cout << endl;
	}
	return 0;
}
