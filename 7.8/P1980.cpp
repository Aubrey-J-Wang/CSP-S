#include <iostream>
#include <cctype>
#include <stack>
const int mod = 10000;
using namespace std;

int main() {
	string s;
	cin >> s;

	s = '+'+s;
	stack<int> numbers;
	stack<char> operators;
	int value = 0;
	for(auto i : s) {
		if(isdigit(i)) value = value * 10 + (i - '0');
		else {
			numbers.push(value);
			operators.push(i);
			value = 0;
		}
	}
	numbers.push(value);

	int sum = 0;
	while(!operators.empty() and !numbers.empty()) {
		while(operators.top() != '*' and !operators.empty() and !numbers.empty()){
			operators.pop();
			sum += numbers.top();
			sum %= mod;
			numbers.pop();
			if(operators.empty() or numbers.empty()){
				cout << sum;
				return 0;
			}
		}
		int x = numbers.top();
		numbers.pop();
		int y = numbers.top();
		numbers.pop();
		numbers.push(x * y % mod);
		operators.pop();
	}
	return 0;
}
