#include <iostream>
#include <map>
#include <vector>
#include <stack>
#define P(a, b) ((a)*(b)%mod)
using namespace std;

const int mod = 10007;

stack<int> numbers_a, numbers_b; // Stacks for operation numbers.
stack<char> operatr; // Stack for operators.
map<char, int> level;

void calculate() {
	int y_a = numbers_a.top(), y_b = numbers_b.top();
	numbers_a.pop(), numbers_b.pop();

	int x_a = numbers_a.top(), x_b = numbers_b.top();
	numbers_a.pop(), numbers_b.pop();

	numbers_a.push(operatr.top() == '+' ? P(x_a, y_a) : (P(x_b, y_a) + P(x_a, y_b) + P(x_a, y_a)) % mod);
	numbers_b.push(operatr.top() == '*' ? P(x_b, y_b) : (P(x_b, y_a) + P(x_a, y_b) + P(x_b, y_b)) % mod);
	operatr.pop();
}

int main() {
	int n;
	cin >> n;
	vector<char> a(n + 1, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];

	a[0] = '(', a[n + 1] = ')';
	string b = "";
	for (int i = 1; i <= n; i++) { // Extend the input string to a string with underlines, restored into b.
		if (a[i] == '+' or a[i] == '*') {
			if (a[i - 1] != ')') { // If the symbol on the left is not ')', we can add an underline.
				if (b[b.length() - 1] != 'X') b += 'X'; // However, there cannot be two consecutive underlines.
			}
			b += a[i];
			if (a[i + 1] != '(') b +=  'X'; // Check the right.
		} else b += a[i]; // If the current character is a bracket, just copy.
	}

	level['('] = 0, level['+'] = 1, level['*'] = 2;

	for (auto i : b)
		if (i == 'X') numbers_a.push(1), numbers_b.push(1); // If met underline...
		else if (i == '(') operatr.push('(');
		else if (i == ')') { // If met right bracket ')', pop and calculate.
			while (operatr.top() != '(')  calculate();
			operatr.pop();
		} else { // Else, the operated operator now is either '+' or '*'.
			bool f = true;
			while(f) {
				if (operatr.empty()) f = false;
				else if (level[i] <= level[operatr.top()]) calculate();
//				If the lever of priority is less than that of the top of the stack, pop.
				else f = false;
			}
			operatr.push(i); // If the operator now has a higher priority, push.
		}

	while (!operatr.empty()) calculate(); // If the operator stack is not empty in the end, we still need to calculate.

	while(numbers_a.size() > 1) numbers_a.pop();
	cout << numbers_a.top();
	return 0;
}