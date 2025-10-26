#include<iostream>
#include<stack>
using namespace std;
const int mod = 10007;
stack<char> st2;
stack<int> st0;
stack<int> st1;
map<char, int> level;
string a, b;
int n, n2;

void calc() {
	int a0, a1;
	int b0, b1;
	a0 = st0.top();
	st0.pop();
	a1 = st1.top();
	st1.pop();
	b0 = st0.top();
	st0.pop();
	b1 = st1.top();
	st1.pop();
	char op = st2.top();
	st2.pop();
	if(op == '+') {
		st0.push(a0 * b0 % mod);
		st1.push(((a1 * b0 % mod) + (a0 * b1 % mod) + (a1 * b1 % mod)) % mod);
	} else {
		st0.push(((a1 * b0 % mod) + (a0 * b1 % mod) + (a0 * b0 % mod)) % mod);
		st1.push(a1 * b1 % mod);
	}
}
int main() {
	cin >> n;
	cin >> a;
	a = "(" + a + ')';
	b = " ";
	for(int i = 0; i <= n + 1; ++i)
		if(a[i] == '+' || a[i] == '*') {
			if(a[i - 1] != ')' && b[n2] != '_') {
				++n2;
				b += '_';
			}
			++n2;
			b += a[i];
			if(a[i + 1] != '(') {
				++n2;
				b += '_';
			}
		} else {
			++n2;
			b += a[i];
		}
	n = n2;
	a = b;
	level['('] = 0;
	level['+'] = 1;
	level['*'] = 2;
	for(int i = 1; i <= n; ++i)
		if(a[i] == '_') {
			st0.push(1);
			st1.push(1);
		} else if(a[i] == '(')
			st2.push('(');
		else if(a[i] == ')') {
			while(st2.top() != '(')
				calc();
			st2.pop();
		} else {
			while(!st2.empty() && level[a[i]] <= level[st2.top()])
				calc();
			st2.push(a[i]);
		}
	cout << st0.top() << endl;
}
