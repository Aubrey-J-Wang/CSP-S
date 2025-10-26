// The code is moderized to C++ STL.
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#define P(a, b) ((a)*(b)%mod)
using namespace std;

const int mod = 10007;

stack<int> numbers_0, numbers_1;
// Stacks for possibility numbers, numbers_0 is the possibilities s.t. the result is 0, numbers_1 is the
// possibilities for 1.
stack<char> operatr; // Stack for operators.
map<char, int> level;

void calculate() {
	int y_0 = numbers_0.top(), y_1 = numbers_1.top();
	numbers_0.pop(), numbers_1.pop();

	int x_0 = numbers_0.top(), x_1 = numbers_1.top();
	numbers_0.pop(), numbers_1.pop();

//	Calculate the possibility situations after this calculation.
	numbers_0.push(operatr.top() == '+' ? P(x_0, y_0) : (P(x_1, y_0) + P(x_0, y_1) + P(x_0, y_0)) % mod);
	numbers_1.push(operatr.top() == '*' ? P(x_1, y_1) : (P(x_1, y_0) + P(x_0, y_1) + P(x_1, y_1)) % mod);
	operatr.pop();
}

int main() {
	int n;
	cin >> n;
	string a;
	cin >> a;

	a = '(' + a + ')';
	string b = " "; // In b, 'X' denotes an underline.
	for (int i = 1; i <= n; i++) { // Extend the input to a string with underlines, restored in b.
		if (a[i] == '+' or a[i] == '*') {
			if (a[i - 1] != ')') { // There cannot be an underline beside brackets.
				if (b[b.length() - 1] != 'X') b += 'X'; // However, there cannot be two consecutive underlines.
			}
			b += a[i];
			if (a[i + 1] != '(') b +=  'X'; // The right.
		} else b += a[i]; // Else, if the current character is a bracket, just copy.
	}

	level['('] = 0, level['+'] = 1, level['*'] = 2;

	for (auto i : b)
		if (i == 'X') numbers_0.push(1), numbers_1.push(1); // If met underline, initialize the possibilities as 1.
		else if (i == '(') operatr.push('(');
		else if (i == ')') { // If met right bracket ')', pop and calculate.
			while (operatr.top() != '(')  calculate(); // Calculate while the brackets are not finished.
			operatr.pop();
		} else { // Else, the operated operator now is either '+' or '*'.
			bool f = true;
			while(!operatr.empty() and level[i] <= level[operatr.top()]) calculate();
//				If the level of priority is less than that of the top of the stack, pop.
			operatr.push(i); // If the operator now has a higher priority, push.
		}

	while (!operatr.empty()) calculate(); // If the operator stack is not empty in the end, we still need to calculate.

	while(numbers_0.size() > 1) numbers_0.pop();
	cout << numbers_0.top();
	return 0;
}