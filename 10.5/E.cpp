#include <iostream>
#include <vector>
#include <stack>
#include <map>
#define int long long
using namespace std;
int read();
void write(int x);

const int mod = 10007;
stack<int> possibility_0, possibility_1; // possibility_0: Possibility of having '0'; possibility_1: Possibility of having '1';
stack<char> st_op; // st_op: Stack of operators.
map<char, int> level;

void calc() {
	int a0 = possibility_0.top();
	possibility_0.pop();
	int b0 = possibility_0.top();
	possibility_0.pop();
	
	int a1 = possibility_1.top();
	possibility_1.pop();
	int b1 = possibility_1.top();
	possibility_1.pop();
	
	char op = st_op.top();
	st_op.pop();
	
	if(op == '+') {
		possibility_0.push(a0 * b0 % mod); // 0 + 0 = 0 only.
		possibility_1.push((a1 * b0 + a0 * b1 + a1 * b1) % mod); // 0 + 1 = 1, 1 + 0 = 1, 1 + 1 = 1.
	} else {
		possibility_0.push((a1 * b0 + a0 * b1 + a0 * b0) % mod); // 0 * 0 = 0, 0 * 1 = 0, 1 * 0 = 0.
		possibility_1.push(a1 * b1 % mod); // 1 * 1 = 1 only.
	}
}
signed main() {
	int n = read();
	string a, b;
	cin >> a;
	a = "(" + a + ")";
	b = " ";

	for(int i = 0; i < a.length(); i++)
		if(a[i] == '+' || a[i] == '*') {
			if(a[i - 1] != ')' && b[b.length()-1] != '_') b += '_';
			b += a[i];
			if(a[i + 1] != '(')	b += '_';
		} else b += a[i];
	
	swap(a, b);
	level['('] = 0, level['+'] = 1, level['*'] = 2;
	
	for(int i = 1; i < a.length(); ++i)
		if(a[i] == '_') possibility_0.push(1), possibility_1.push(1);
		else if(a[i] == '(') st_op.push('(');
		else if(a[i] == ')') {
			while(st_op.top() != '(') calc();
			st_op.pop();
		} else { // a[i] = '+' or '*'
			while(!st_op.empty() && level[a[i]] <= level[st_op.top()]) calc();
				
			st_op.push(a[i]); // Enter the operator with high priority.
		}
		
	while(!st_op.empty()) calc(); // There may remain certain operators with lower priority after we searched the string.
	
	write(possibility_0.top());
	return 0;
}


int read() {
	int x = 0, f = 1;
	char c = getchar();
	
	while(c < '0' || c > '9') {
		if(c == '-') f = -f;
		
		c = getchar();
	}
	
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	
	return x * f;
}

void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	
	if(x > 9) write(x / 10);
	
	putchar(x % 10 + '0');
}

